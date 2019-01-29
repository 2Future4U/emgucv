//----------------------------------------------------------------------------
//
//  Copyright (C) 2004-2019 by EMGU Corporation. All rights reserved.
//
//----------------------------------------------------------------------------

#pragma once
#ifndef EMGU_SALIENCY_C_H
#define EMGU_SALIENCY_C_H

#include "opencv2/core/core_c.h"
#include "opencv2/saliency.hpp"

CVAPI(cv::saliency::StaticSaliencySpectralResidual*) cveStaticSaliencySpectralResidualCreate(cv::saliency::StaticSaliency** static_saliency, cv::saliency::Saliency** saliency, cv::Algorithm** algorithm, cv::Ptr<cv::saliency::StaticSaliencySpectralResidual>** sharedPtr);
CVAPI(void) cveStaticSaliencySpectralResidualRelease(cv::saliency::StaticSaliencySpectralResidual** saliency, cv::Ptr<cv::saliency::StaticSaliencySpectralResidual>** sharedPtr);

CVAPI(cv::saliency::StaticSaliencyFineGrained*) cveStaticSaliencyFineGrainedCreate(cv::saliency::StaticSaliency** static_saliency, cv::saliency::Saliency** saliency, cv::Algorithm** algorithm, cv::Ptr<cv::saliency::StaticSaliencyFineGrained>** sharedPtr);
CVAPI(void) cveStaticSaliencyFineGrainedRelease(cv::saliency::StaticSaliencyFineGrained** saliency, cv::Ptr<cv::saliency::StaticSaliencyFineGrained>** sharedPtr);

CVAPI(cv::saliency::MotionSaliencyBinWangApr2014*) cveMotionSaliencyBinWangApr2014Create(cv::saliency::MotionSaliency** motion_saliency, cv::saliency::Saliency** saliency, cv::Algorithm** algorithm, cv::Ptr<cv::saliency::MotionSaliencyBinWangApr2014>** sharedPtr);
CVAPI(void) cveMotionSaliencyBinWangApr2014Release(cv::saliency::MotionSaliencyBinWangApr2014** saliency, cv::Ptr<cv::saliency::MotionSaliencyBinWangApr2014>** sharedPtr);

CVAPI(cv::saliency::ObjectnessBING*) cveObjectnessBINGCreate(cv::saliency::Objectness** objectness_saliency, cv::saliency::Saliency** saliency, cv::Algorithm** algorithm, cv::Ptr<cv::saliency::ObjectnessBING>** sharedPtr);
CVAPI(void) cveObjectnessBINGRelease(cv::saliency::ObjectnessBING** saliency, cv::Ptr<cv::saliency::ObjectnessBING>** sharedPtr);


CVAPI(bool) cveSaliencyComputeSaliency(cv::saliency::Saliency* saliency, cv::_InputArray* image, cv::_OutputArray* saliencyMap);

CVAPI(bool) cveStaticSaliencyComputeBinaryMap(cv::saliency::StaticSaliency* saliency, cv::_InputArray* saliencyMap, cv::_OutputArray* binaryMap);

CVAPI(bool) cveSaliencyMotionInit(cv::saliency::Saliency* saliency);
CVAPI(void) cveSaliencyMotionSetImageSize(cv::saliency::Saliency* saliency, int width, int height);

CVAPI(void) cveObjectnessBINGSetTrainingPath(cv::saliency::ObjectnessBING* saliency, cv::String* trainingPath);

CVAPI(void) cveObjectnessBINGGetObjectnessValues(cv::saliency::ObjectnessBING* saliency, std::vector<float>* values);

//CVAPI(cv::Algorithm*) cveSaliencyGetAlgorithm(cv::saliency::Saliency* saliency);
#endif