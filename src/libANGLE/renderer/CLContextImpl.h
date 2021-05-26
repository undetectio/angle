//
// Copyright 2021 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// CLContextImpl.h: Defines the abstract rx::CLContextImpl class.

#ifndef LIBANGLE_RENDERER_CLCONTEXTIMPL_H_
#define LIBANGLE_RENDERER_CLCONTEXTIMPL_H_

#include "libANGLE/renderer/CLCommandQueueImpl.h"
#include "libANGLE/renderer/CLDeviceImpl.h"
#include "libANGLE/renderer/CLMemoryImpl.h"
#include "libANGLE/renderer/CLProgramImpl.h"
#include "libANGLE/renderer/CLSamplerImpl.h"

namespace rx
{

class CLContextImpl : angle::NonCopyable
{
  public:
    using Ptr = std::unique_ptr<CLContextImpl>;

    CLContextImpl(const cl::Context &context);
    virtual ~CLContextImpl();

    virtual cl::DeviceRefList getDevices() const = 0;

    virtual CLCommandQueueImpl::Ptr createCommandQueue(const cl::CommandQueue &commandQueue,
                                                       cl_int *errcodeRet) = 0;

    virtual CLMemoryImpl::Ptr createBuffer(const cl::Buffer &buffer,
                                           size_t size,
                                           void *hostPtr,
                                           cl_int *errcodeRet) = 0;

    virtual CLMemoryImpl::Ptr createImage(const cl::Image &image,
                                          const cl_image_format &format,
                                          const cl::ImageDescriptor &desc,
                                          void *hostPtr,
                                          cl_int *errcodeRet) = 0;

    virtual CLSamplerImpl::Ptr createSampler(const cl::Sampler &sampler, cl_int *errcodeRet) = 0;

    virtual CLProgramImpl::Ptr createProgramWithSource(const cl::Program &program,
                                                       const std::string &source,
                                                       cl_int *errcodeRet) = 0;

    virtual CLProgramImpl::Ptr createProgramWithIL(const cl::Program &program,
                                                   const void *il,
                                                   size_t length,
                                                   cl_int *errcodeRet) = 0;

    virtual CLProgramImpl::Ptr createProgramWithBinary(const cl::Program &program,
                                                       const cl::Binaries &binaries,
                                                       cl_int *binaryStatus,
                                                       cl_int *errcodeRet) = 0;

    virtual CLProgramImpl::Ptr createProgramWithBuiltInKernels(const cl::Program &program,
                                                               const char *kernel_names,
                                                               cl_int *errcodeRet) = 0;

  protected:
    const cl::Context &mContext;
};

}  // namespace rx

#endif  // LIBANGLE_RENDERER_CLCONTEXTIMPL_H_
