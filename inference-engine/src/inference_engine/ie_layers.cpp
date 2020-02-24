/*
 * INTEL CONFIDENTIAL
 * Copyright 2016 Intel Corporation.
 *
 * The source code contained or described herein and all documents
 * related to the source code ("Material") are owned by Intel Corporation
 * or its suppliers or licensors. Title to the Material remains with
 * Intel Corporation or its suppliers and licensors. The Material may
 * contain trade secrets and proprietary and confidential information
 * of Intel Corporation and its suppliers and licensors, and is protected
 * by worldwide copyright and trade secret laws and treaty provisions.
 * No part of the Material may be used, copied, reproduced, modified,
 * published, uploaded, posted, transmitted, distributed, or disclosed
 * in any way without Intel's prior express written permission.
 *
 * No license under any patent, copyright, trade secret or other
 * intellectual property right is granted to or conferred upon you by
 * disclosure or delivery of the Materials, either expressly, by implication,
 * inducement, estoppel or otherwise. Any license under such intellectual
 * property rights must be express and approved by Intel in writing.
 *
 * Include any supplier copyright notices as supplier requires Intel to use.
 *
 * Include supplier trademarks or logos as supplier requires Intel to use,
 * preceded by an asterisk. An asterisked footnote can be added as follows:
 * *Third Party trademarks are the property of their respective owners.
 *
 * Unless otherwise agreed by Intel in writing, you may not remove or alter
 * this notice or any other notice embedded in Materials by Intel or Intel's
 * suppliers or licensors in any way.
 */

#include "ie_layers.h"
#include "ie_data.h"
#include <memory>
#include <string>
#include <map>

using namespace InferenceEngine;
#if defined(__ANDROID__)
CNNLayer::~CNNLayer() {

}

WeightableLayer::~WeightableLayer(){

}

ConvolutionLayer::~ConvolutionLayer(){

}

DeconvolutionLayer::~DeconvolutionLayer(){

}

DeformableConvolutionLayer::~DeformableConvolutionLayer(){

}

PoolingLayer::~PoolingLayer(){

}

BinaryConvolutionLayer::~BinaryConvolutionLayer(){

}

FullyConnectedLayer::~FullyConnectedLayer(){

}

ConcatLayer::~ConcatLayer(){

}

SplitLayer::~SplitLayer(){

}

NormLayer::~NormLayer(){

}

SoftMaxLayer::~SoftMaxLayer(){

}

GRNLayer::~GRNLayer(){

}

MVNLayer::~MVNLayer(){

}

ReLULayer::~ReLULayer(){

}

ClampLayer::~ClampLayer(){

}

ReLU6Layer::~ReLU6Layer(){

}

EltwiseLayer::~EltwiseLayer(){

}

CropLayer::~CropLayer(){

}

ReshapeLayer::~ReshapeLayer(){

}

TileLayer::~TileLayer(){

}

ScaleShiftLayer::~ScaleShiftLayer(){

}

TensorIterator::~TensorIterator(){

}

RNNCellBase::~RNNCellBase(){

}

LSTMCell::~LSTMCell(){

}

GRUCell::~GRUCell(){

}

RNNCell::~RNNCell(){

}

RNNSequenceLayer::~RNNSequenceLayer(){

}

PReLULayer::~PReLULayer(){

}

PowerLayer::~PowerLayer(){

}

BatchNormalizationLayer::~BatchNormalizationLayer(){

}

GemmLayer::~GemmLayer(){

}

PadLayer::~PadLayer(){

}

GatherLayer::~GatherLayer(){

}

StridedSliceLayer::~StridedSliceLayer(){

}

ShuffleChannelsLayer::~ShuffleChannelsLayer(){

}

DepthToSpaceLayer::~DepthToSpaceLayer(){

}

SpaceToDepthLayer::~SpaceToDepthLayer(){

}

SparseFillEmptyRowsLayer::~SparseFillEmptyRowsLayer(){

}

ReverseSequenceLayer::~ReverseSequenceLayer(){

}

OneHotLayer::~OneHotLayer(){

}

RangeLayer::~RangeLayer(){

}

FillLayer::~FillLayer(){

}

SelectLayer::~SelectLayer(){

}

BroadcastLayer::~BroadcastLayer(){

}

QuantizeLayer::~QuantizeLayer(){

}

MathLayer::~MathLayer(){

}

ReduceLayer::~ReduceLayer(){

}

TopKLayer::~TopKLayer(){

}

UniqueLayer::~UniqueLayer(){

}

NonMaxSuppressionLayer::~NonMaxSuppressionLayer(){

}

ScatterLayer::~ScatterLayer(){

}

TanHLayer::~TanHLayer(){

}

SigmoidLayer::~SigmoidLayer(){

}

#endif