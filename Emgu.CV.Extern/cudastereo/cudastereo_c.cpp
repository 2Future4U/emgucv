//----------------------------------------------------------------------------
//
//  Copyright (C) 2004-2019 by EMGU Corporation. All rights reserved.
//
//----------------------------------------------------------------------------

#include "cudastereo_c.h"

cv::cuda::StereoBM* cudaStereoBMCreate(int numDisparities, int blockSize, cv::Ptr<cv::cuda::StereoBM>** sharedPtr)
{
	cv::Ptr<cv::cuda::StereoBM> ptr = cv::cuda::createStereoBM(numDisparities, blockSize);
	*sharedPtr = new cv::Ptr<cv::cuda::StereoBM>(ptr);
	return ptr.get();
}

void cudaStereoBMFindStereoCorrespondence(cv::cuda::StereoBM* stereo, cv::_InputArray* left, cv::_InputArray* right, cv::_OutputArray* disparity, cv::cuda::Stream* stream)
{
	stereo->compute(*left, *right, *disparity, stream ? *stream : cv::cuda::Stream::Null());
}

void cudaStereoBMRelease(cv::Ptr<cv::cuda::StereoBM>** stereoBM)
{
	delete *stereoBM;
	*stereoBM = 0;
}

cv::cuda::StereoConstantSpaceBP* cudaStereoConstantSpaceBPCreate(int ndisp, int iters, int levels, int nr_plane, cv::Ptr<cv::cuda::StereoConstantSpaceBP>** sharedPtr)
{
	cv::Ptr<cv::cuda::StereoConstantSpaceBP> ptr = cv::cuda::createStereoConstantSpaceBP(ndisp, iters, levels, nr_plane, CV_32F);
	*sharedPtr = new cv::Ptr<cv::cuda::StereoConstantSpaceBP>(ptr);
	return ptr.get();
}

void cudaStereoConstantSpaceBPFindStereoCorrespondence(cv::cuda::StereoConstantSpaceBP* stereo, cv::_InputArray* left, cv::_InputArray* right, cv::_OutputArray* disparity, cv::cuda::Stream* stream)
{
	stereo->compute(*left, *right, *disparity, stream ? *stream : cv::cuda::Stream::Null());
}

void cudaStereoConstantSpaceBPRelease(cv::Ptr<cv::cuda::StereoConstantSpaceBP>** stereo)
{
	delete *stereo;
	*stereo = 0;
}

cv::cuda::DisparityBilateralFilter* cudaDisparityBilateralFilterCreate(int ndisp, int radius, int iters, cv::Ptr<cv::cuda::DisparityBilateralFilter>** sharedPtr)
{
	cv::Ptr<cv::cuda::DisparityBilateralFilter> ptr = cv::cuda::createDisparityBilateralFilter(ndisp, radius, iters);
	*sharedPtr = new cv::Ptr<cv::cuda::DisparityBilateralFilter>(ptr);
	return ptr.get();
}

void cudaDisparityBilateralFilterApply(cv::cuda::DisparityBilateralFilter* filter, cv::_InputArray* disparity, cv::_InputArray* image, cv::_OutputArray* dst, cv::cuda::Stream* stream)
{
	filter->apply(*disparity, *image, *dst, stream ? *stream : cv::cuda::Stream::Null());
}

void cudaDisparityBilateralFilterRelease(cv::Ptr<cv::cuda::DisparityBilateralFilter>** filter)
{
	delete *filter;
	*filter = 0;
}


void cudaDrawColorDisp(cv::_InputArray* srcDisp, cv::_OutputArray* dstDisp, int ndisp, cv::cuda::Stream* stream)
{
	cv::cuda::drawColorDisp(*srcDisp, *dstDisp, ndisp, stream ? *stream : cv::cuda::Stream::Null());
}

