// Copyright (C) 2018-2019 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <vpu/frontend/frontend.hpp>

#include <memory>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

#include <vpu/utils/extra.hpp>

namespace vpu {

namespace {

class ExpandStage final : public StageNode {
protected:
    StagePtr cloneImpl() const override {
        return std::make_shared<ExpandStage>(*this);
    }

    DataMap<float> propagateScaleFactorsImpl(
            const DataMap<float>&,
            ScalePropagationStep) override {
        VPU_THROW_EXCEPTION << "Must never be called";
    }

    DataMap<DimsOrder> propagateDataOrderImpl() const override {
        IE_ASSERT(_inputEdges.size() == 1);
        IE_ASSERT(_outputEdges.size() == 1);

        auto input = _inputEdges[0]->input();
        auto output = _outputEdges[0]->output();

        DataMap<DimsOrder> out;

        out[output] = input->desc().dimsOrder();

        return out;
    }

    DataMap<StridesRequirement> getDataStridesRequirementsImpl() const override {
        IE_ASSERT(_inputEdges.size() == 1);
        IE_ASSERT(_outputEdges.size() == 1);

        auto input = _inputEdges[0]->input();
        auto output = _outputEdges[0]->output();

        auto dimsOrder = output->desc().dimsOrder();

        //
        // Get smallest Dim over which Expand is done.
        //

        auto minExpandDimInd = dimsOrder.numDims();

        for (const auto& p : output->desc().dims()) {
            if (input->desc().dim(p.first) != p.second) {
                minExpandDimInd = std::min(minExpandDimInd, dimsOrder.dimInd(p.first));
            }
        }

        IE_ASSERT(minExpandDimInd < dimsOrder.numDims());

        //
        // Initial StridesRequirement for input and output.
        //

        auto outputReqs = output->requiredStrides();

        auto inputReqs = outputReqs;
        for (int i = minExpandDimInd + 1; i < dimsOrder.numDims(); ++i) {
            inputReqs.remove(i);
        }

        //
        // Merge output consumers StridesRequirement.
        //

        for (const auto& consumer : output->consumers()) {
            auto consumerInfo = consumer->getDataStridesRequirements();

            auto consumerStrideIt = consumerInfo.find(output);
            if (consumerStrideIt != consumerInfo.end()) {
                auto consumerReqs = consumerStrideIt->second;

                for (int i = 0; i < minExpandDimInd + 1; ++i) {
                    if (outputReqs.get(i) == DimStride::Any) {
                        if (consumerReqs.get(i) != DimStride::Any) {
                            inputReqs.add(i, consumerReqs.get(i));
                            outputReqs.add(i, consumerReqs.get(i));
                        }
                    }
                }
            }
        }

        //
        // Return merged StridesRequirements.
        //

        DataMap<StridesRequirement> out;

        out[input] = inputReqs;
        out[output] = outputReqs;

        return out;
    }

    void finalizeDataLayoutImpl() override {
    }

    DataMap<BatchSupport> getBatchSupportInfoImpl() const override {
        return DataMap<BatchSupport>();
    }

    void finalCheckImpl() const override {
    }

    void serializeParamsImpl(BlobSerializer&) const override {
        VPU_THROW_EXCEPTION << "Must never be called";
    }

    void serializeDataImpl(BlobSerializer&) const override {
        VPU_THROW_EXCEPTION << "Must never be called";
    }
};

}  // namespace

Stage StageBuilder::addExpandStage(
        const Model::Ptr& model,
        const std::string& name,
        const ie::CNNLayerPtr& layer,
        const Data& input,
        const Data& output,
        const DimValues& offset) {
    auto stage = model->addNewStage<ExpandStage>(
        name,
        StageType::Expand,
        layer,
        {input},
        {output});

    stage->attrs().set<DimValues>("offset", offset);

    return stage;
}

}  // namespace vpu
