//----------------------------------------------------------------------------
//
//  Copyright (C) 2004-2019 by EMGU Corporation. All rights reserved.
//
//----------------------------------------------------------------------------

#pragma once
#ifndef EMGU_VIDEO_C_H
#define EMGU_VIDEO_C_H

#include "opencv2/core/core_c.h"
#include "opencv2/optflow.hpp"

CVAPI(void) cveUpdateMotionHistory(cv::_InputArray* silhouette, cv::_InputOutputArray* mhi, double timestamp, double duration);
CVAPI(void) cveCalcMotionGradient(cv::_InputArray* mhi, cv::_OutputArray* mask, cv::_OutputArray* orientation, double delta1, double delta2, int apertureSize);
CVAPI(void) cveCalcGlobalOrientation(cv::_InputArray* orientation, cv::_InputArray* mask, cv::_InputArray* mhi, double timestamp, double duration);
CVAPI(void) cveSegmentMotion(cv::_InputArray* mhi, cv::_OutputArray* segmask, std::vector< cv::Rect >* boundingRects, double timestamp, double segThresh);

CVAPI(cv::DenseOpticalFlow*) cveOptFlowDeepFlowCreate(cv::Algorithm** algorithm, cv::Ptr<cv::DenseOpticalFlow>** sharedPtr);
CVAPI(cv::DenseOpticalFlow*) cveOptFlowPCAFlowCreate(cv::Algorithm** algorithm, cv::Ptr<cv::DenseOpticalFlow>** sharedPtr);

CVAPI(cv::optflow::DualTVL1OpticalFlow*) cveDenseOpticalFlowCreateDualTVL1(cv::DenseOpticalFlow** denseOpticalFlow, cv::Algorithm** algorithm, cv::Ptr<cv::optflow::DualTVL1OpticalFlow>** sharedPtr);
CVAPI(void) cveDualTVL1OpticalFlowRelease(cv::Ptr<cv::optflow::DualTVL1OpticalFlow>** sharedPtr);

#endif