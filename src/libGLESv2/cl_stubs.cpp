//
// Copyright 2021 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// cl_stubs.cpp: Stubs for CL entry points.

#include "libGLESv2/cl_stubs_autogen.h"

#include "libGLESv2/proc_table_cl.h"

#include "libANGLE/CLBuffer.h"
#include "libANGLE/CLCommandQueue.h"
#include "libANGLE/CLContext.h"
#include "libANGLE/CLDevice.h"
#include "libANGLE/CLImage.h"
#include "libANGLE/CLMemory.h"
#include "libANGLE/CLPlatform.h"

#define WARN_NOT_SUPPORTED(command)                                         \
    do                                                                      \
    {                                                                       \
        static bool sWarned = false;                                        \
        if (!sWarned)                                                       \
        {                                                                   \
            sWarned = true;                                                 \
            WARN() << "OpenCL command " #command " is not (yet) supported"; \
        }                                                                   \
    } while (0)

namespace cl
{

cl_int IcdGetPlatformIDsKHR(cl_uint num_entries, cl_platform_id *platforms, cl_uint *num_platforms)
{
    return Platform::GetPlatformIDs(num_entries, platforms, num_platforms);
}

cl_int GetPlatformIDs(cl_uint num_entries, cl_platform_id *platforms, cl_uint *num_platforms)
{
    return Platform::GetPlatformIDs(num_entries, platforms, num_platforms);
}

cl_int GetPlatformInfo(cl_platform_id platform,
                       PlatformInfo param_name,
                       size_t param_value_size,
                       void *param_value,
                       size_t *param_value_size_ret)
{
    return Platform::CastOrDefault(platform)->getInfo(param_name, param_value_size, param_value,
                                                      param_value_size_ret);
}

cl_int GetDeviceIDs(cl_platform_id platform,
                    cl_device_type device_type,
                    cl_uint num_entries,
                    cl_device_id *devices,
                    cl_uint *num_devices)
{
    return Platform::CastOrDefault(platform)->getDeviceIDs(device_type, num_entries, devices,
                                                           num_devices);
}

cl_int GetDeviceInfo(cl_device_id device,
                     DeviceInfo param_name,
                     size_t param_value_size,
                     void *param_value,
                     size_t *param_value_size_ret)
{
    return static_cast<Device *>(device)->getInfo(param_name, param_value_size, param_value,
                                                  param_value_size_ret);
}

cl_int CreateSubDevices(cl_device_id in_device,
                        const cl_device_partition_property *properties,
                        cl_uint num_devices,
                        cl_device_id *out_devices,
                        cl_uint *num_devices_ret)
{
    return static_cast<Device *>(in_device)->createSubDevices(properties, num_devices, out_devices,
                                                              num_devices_ret);
}

cl_int RetainDevice(cl_device_id device)
{
    static_cast<Device *>(device)->retain();
    return CL_SUCCESS;
}

cl_int ReleaseDevice(cl_device_id device)
{
    static_cast<Device *>(device)->release();
    return CL_SUCCESS;
}

cl_int SetDefaultDeviceCommandQueue(cl_context context,
                                    cl_device_id device,
                                    cl_command_queue command_queue)
{
    WARN_NOT_SUPPORTED(SetDefaultDeviceCommandQueue);
    return 0;
}

cl_int GetDeviceAndHostTimer(cl_device_id device,
                             cl_ulong *device_timestamp,
                             cl_ulong *host_timestamp)
{
    WARN_NOT_SUPPORTED(GetDeviceAndHostTimer);
    return 0;
}

cl_int GetHostTimer(cl_device_id device, cl_ulong *host_timestamp)
{
    WARN_NOT_SUPPORTED(GetHostTimer);
    return 0;
}

cl_context CreateContext(const cl_context_properties *properties,
                         cl_uint num_devices,
                         const cl_device_id *devices,
                         void(CL_CALLBACK *pfn_notify)(const char *errinfo,
                                                       const void *private_info,
                                                       size_t cb,
                                                       void *user_data),
                         void *user_data,
                         cl_int *errcode_ret)
{
    return Platform::CreateContext(properties, num_devices, devices, pfn_notify, user_data,
                                   errcode_ret);
}

cl_context CreateContextFromType(const cl_context_properties *properties,
                                 cl_device_type device_type,
                                 void(CL_CALLBACK *pfn_notify)(const char *errinfo,
                                                               const void *private_info,
                                                               size_t cb,
                                                               void *user_data),
                                 void *user_data,
                                 cl_int *errcode_ret)
{
    return Platform::CreateContextFromType(properties, device_type, pfn_notify, user_data,
                                           errcode_ret);
}

cl_int RetainContext(cl_context context)
{
    static_cast<Context *>(context)->retain();
    return CL_SUCCESS;
}

cl_int ReleaseContext(cl_context context)
{
    static_cast<Context *>(context)->release();
    return CL_SUCCESS;
}

cl_int GetContextInfo(cl_context context,
                      ContextInfo param_name,
                      size_t param_value_size,
                      void *param_value,
                      size_t *param_value_size_ret)
{
    return static_cast<Context *>(context)->getInfo(param_name, param_value_size, param_value,
                                                    param_value_size_ret);
}

cl_int SetContextDestructorCallback(cl_context context,
                                    void(CL_CALLBACK *pfn_notify)(cl_context context,
                                                                  void *user_data),
                                    void *user_data)
{
    WARN_NOT_SUPPORTED(SetContextDestructorCallback);
    return 0;
}

cl_command_queue CreateCommandQueueWithProperties(cl_context context,
                                                  cl_device_id device,
                                                  const cl_queue_properties *properties,
                                                  cl_int *errcode_ret)
{
    return static_cast<Context *>(context)->createCommandQueueWithProperties(device, properties,
                                                                             errcode_ret);
}

cl_int RetainCommandQueue(cl_command_queue command_queue)
{
    static_cast<CommandQueue *>(command_queue)->retain();
    return CL_SUCCESS;
}

cl_int ReleaseCommandQueue(cl_command_queue command_queue)
{
    static_cast<CommandQueue *>(command_queue)->release();
    return CL_SUCCESS;
}

cl_int GetCommandQueueInfo(cl_command_queue command_queue,
                           CommandQueueInfo param_name,
                           size_t param_value_size,
                           void *param_value,
                           size_t *param_value_size_ret)
{
    return static_cast<CommandQueue *>(command_queue)
        ->getInfo(param_name, param_value_size, param_value, param_value_size_ret);
}

cl_mem CreateBuffer(cl_context context,
                    cl_mem_flags flags,
                    size_t size,
                    void *host_ptr,
                    cl_int *errcode_ret)
{
    return static_cast<Context *>(context)->createBuffer(nullptr, flags, size, host_ptr,
                                                         errcode_ret);
}

cl_mem CreateBufferWithProperties(cl_context context,
                                  const cl_mem_properties *properties,
                                  cl_mem_flags flags,
                                  size_t size,
                                  void *host_ptr,
                                  cl_int *errcode_ret)
{
    return static_cast<Context *>(context)->createBuffer(properties, flags, size, host_ptr,
                                                         errcode_ret);
}

cl_mem CreateSubBuffer(cl_mem buffer,
                       cl_mem_flags flags,
                       cl_buffer_create_type buffer_create_type,
                       const void *buffer_create_info,
                       cl_int *errcode_ret)
{
    return static_cast<Buffer *>(buffer)->createSubBuffer(flags, buffer_create_type,
                                                          buffer_create_info, errcode_ret);
}

cl_mem CreateImage(cl_context context,
                   cl_mem_flags flags,
                   const cl_image_format *image_format,
                   const cl_image_desc *image_desc,
                   void *host_ptr,
                   cl_int *errcode_ret)
{
    return static_cast<Context *>(context)->createImage(nullptr, flags, image_format, image_desc,
                                                        host_ptr, errcode_ret);
}

cl_mem CreateImageWithProperties(cl_context context,
                                 const cl_mem_properties *properties,
                                 cl_mem_flags flags,
                                 const cl_image_format *image_format,
                                 const cl_image_desc *image_desc,
                                 void *host_ptr,
                                 cl_int *errcode_ret)
{
    return static_cast<Context *>(context)->createImage(properties, flags, image_format, image_desc,
                                                        host_ptr, errcode_ret);
}

cl_mem CreatePipe(cl_context context,
                  cl_mem_flags flags,
                  cl_uint pipe_packet_size,
                  cl_uint pipe_max_packets,
                  const cl_pipe_properties *properties,
                  cl_int *errcode_ret)
{
    WARN_NOT_SUPPORTED(CreatePipe);
    return 0;
}

cl_int RetainMemObject(cl_mem memobj)
{
    static_cast<Memory *>(memobj)->retain();
    return CL_SUCCESS;
}

cl_int ReleaseMemObject(cl_mem memobj)
{
    static_cast<Memory *>(memobj)->release();
    return CL_SUCCESS;
}

cl_int GetSupportedImageFormats(cl_context context,
                                cl_mem_flags flags,
                                MemObjectType image_type,
                                cl_uint num_entries,
                                cl_image_format *image_formats,
                                cl_uint *num_image_formats)
{
    WARN_NOT_SUPPORTED(GetSupportedImageFormats);
    return 0;
}

cl_int GetMemObjectInfo(cl_mem memobj,
                        MemInfo param_name,
                        size_t param_value_size,
                        void *param_value,
                        size_t *param_value_size_ret)
{
    return static_cast<Memory *>(memobj)->getInfo(param_name, param_value_size, param_value,
                                                  param_value_size_ret);
}

cl_int GetImageInfo(cl_mem image,
                    ImageInfo param_name,
                    size_t param_value_size,
                    void *param_value,
                    size_t *param_value_size_ret)
{
    return static_cast<Image *>(image)->getInfo(param_name, param_value_size, param_value,
                                                param_value_size_ret);
}

cl_int GetPipeInfo(cl_mem pipe,
                   PipeInfo param_name,
                   size_t param_value_size,
                   void *param_value,
                   size_t *param_value_size_ret)
{
    WARN_NOT_SUPPORTED(GetPipeInfo);
    return 0;
}

cl_int SetMemObjectDestructorCallback(cl_mem memobj,
                                      void(CL_CALLBACK *pfn_notify)(cl_mem memobj, void *user_data),
                                      void *user_data)
{
    WARN_NOT_SUPPORTED(SetMemObjectDestructorCallback);
    return 0;
}

void *SVMAlloc(cl_context context, cl_svm_mem_flags flags, size_t size, cl_uint alignment)
{
    WARN_NOT_SUPPORTED(SVMAlloc);
    return 0;
}

void SVMFree(cl_context context, void *svm_pointer)
{
    WARN_NOT_SUPPORTED(SVMFree);
}

cl_sampler CreateSamplerWithProperties(cl_context context,
                                       const cl_sampler_properties *sampler_properties,
                                       cl_int *errcode_ret)
{
    return static_cast<Context *>(context)->createSamplerWithProperties(sampler_properties,
                                                                        errcode_ret);
}

cl_int RetainSampler(cl_sampler sampler)
{
    static_cast<Sampler *>(sampler)->retain();
    return CL_SUCCESS;
}

cl_int ReleaseSampler(cl_sampler sampler)
{
    static_cast<Sampler *>(sampler)->release();
    return CL_SUCCESS;
}

cl_int GetSamplerInfo(cl_sampler sampler,
                      SamplerInfo param_name,
                      size_t param_value_size,
                      void *param_value,
                      size_t *param_value_size_ret)
{
    return static_cast<Sampler *>(sampler)->getInfo(param_name, param_value_size, param_value,
                                                    param_value_size_ret);
}

cl_program CreateProgramWithSource(cl_context context,
                                   cl_uint count,
                                   const char **strings,
                                   const size_t *lengths,
                                   cl_int *errcode_ret)
{
    return static_cast<Context *>(context)->createProgramWithSource(count, strings, lengths,
                                                                    errcode_ret);
}

cl_program CreateProgramWithBinary(cl_context context,
                                   cl_uint num_devices,
                                   const cl_device_id *device_list,
                                   const size_t *lengths,
                                   const unsigned char **binaries,
                                   cl_int *binary_status,
                                   cl_int *errcode_ret)
{
    return static_cast<Context *>(context)->createProgramWithBinary(
        num_devices, device_list, lengths, binaries, binary_status, errcode_ret);
}

cl_program CreateProgramWithBuiltInKernels(cl_context context,
                                           cl_uint num_devices,
                                           const cl_device_id *device_list,
                                           const char *kernel_names,
                                           cl_int *errcode_ret)
{
    return static_cast<Context *>(context)->createProgramWithBuiltInKernels(
        num_devices, device_list, kernel_names, errcode_ret);
}

cl_program CreateProgramWithIL(cl_context context,
                               const void *il,
                               size_t length,
                               cl_int *errcode_ret)
{
    return static_cast<Context *>(context)->createProgramWithIL(il, length, errcode_ret);
}

cl_int RetainProgram(cl_program program)
{
    static_cast<Program *>(program)->retain();
    return CL_SUCCESS;
}

cl_int ReleaseProgram(cl_program program)
{
    static_cast<Program *>(program)->release();
    return CL_SUCCESS;
}

cl_int BuildProgram(cl_program program,
                    cl_uint num_devices,
                    const cl_device_id *device_list,
                    const char *options,
                    void(CL_CALLBACK *pfn_notify)(cl_program program, void *user_data),
                    void *user_data)
{
    WARN_NOT_SUPPORTED(BuildProgram);
    return 0;
}

cl_int CompileProgram(cl_program program,
                      cl_uint num_devices,
                      const cl_device_id *device_list,
                      const char *options,
                      cl_uint num_input_headers,
                      const cl_program *input_headers,
                      const char **header_include_names,
                      void(CL_CALLBACK *pfn_notify)(cl_program program, void *user_data),
                      void *user_data)
{
    WARN_NOT_SUPPORTED(CompileProgram);
    return 0;
}

cl_program LinkProgram(cl_context context,
                       cl_uint num_devices,
                       const cl_device_id *device_list,
                       const char *options,
                       cl_uint num_input_programs,
                       const cl_program *input_programs,
                       void(CL_CALLBACK *pfn_notify)(cl_program program, void *user_data),
                       void *user_data,
                       cl_int *errcode_ret)
{
    WARN_NOT_SUPPORTED(LinkProgram);
    return 0;
}

cl_int SetProgramReleaseCallback(cl_program program,
                                 void(CL_CALLBACK *pfn_notify)(cl_program program, void *user_data),
                                 void *user_data)
{
    WARN_NOT_SUPPORTED(SetProgramReleaseCallback);
    return 0;
}

cl_int SetProgramSpecializationConstant(cl_program program,
                                        cl_uint spec_id,
                                        size_t spec_size,
                                        const void *spec_value)
{
    WARN_NOT_SUPPORTED(SetProgramSpecializationConstant);
    return 0;
}

cl_int UnloadPlatformCompiler(cl_platform_id platform)
{
    WARN_NOT_SUPPORTED(UnloadPlatformCompiler);
    return 0;
}

cl_int GetProgramInfo(cl_program program,
                      ProgramInfo param_name,
                      size_t param_value_size,
                      void *param_value,
                      size_t *param_value_size_ret)
{
    return static_cast<Program *>(program)->getInfo(param_name, param_value_size, param_value,
                                                    param_value_size_ret);
}

cl_int GetProgramBuildInfo(cl_program program,
                           cl_device_id device,
                           ProgramBuildInfo param_name,
                           size_t param_value_size,
                           void *param_value,
                           size_t *param_value_size_ret)
{
    WARN_NOT_SUPPORTED(GetProgramBuildInfo);
    return 0;
}

cl_kernel CreateKernel(cl_program program, const char *kernel_name, cl_int *errcode_ret)
{
    WARN_NOT_SUPPORTED(CreateKernel);
    return 0;
}

cl_int CreateKernelsInProgram(cl_program program,
                              cl_uint num_kernels,
                              cl_kernel *kernels,
                              cl_uint *num_kernels_ret)
{
    WARN_NOT_SUPPORTED(CreateKernelsInProgram);
    return 0;
}

cl_kernel CloneKernel(cl_kernel source_kernel, cl_int *errcode_ret)
{
    WARN_NOT_SUPPORTED(CloneKernel);
    return 0;
}

cl_int RetainKernel(cl_kernel kernel)
{
    WARN_NOT_SUPPORTED(RetainKernel);
    return 0;
}

cl_int ReleaseKernel(cl_kernel kernel)
{
    WARN_NOT_SUPPORTED(ReleaseKernel);
    return 0;
}

cl_int SetKernelArg(cl_kernel kernel, cl_uint arg_index, size_t arg_size, const void *arg_value)
{
    WARN_NOT_SUPPORTED(SetKernelArg);
    return 0;
}

cl_int SetKernelArgSVMPointer(cl_kernel kernel, cl_uint arg_index, const void *arg_value)
{
    WARN_NOT_SUPPORTED(SetKernelArgSVMPointer);
    return 0;
}

cl_int SetKernelExecInfo(cl_kernel kernel,
                         KernelExecInfo param_name,
                         size_t param_value_size,
                         const void *param_value)
{
    WARN_NOT_SUPPORTED(SetKernelExecInfo);
    return 0;
}

cl_int GetKernelInfo(cl_kernel kernel,
                     KernelInfo param_name,
                     size_t param_value_size,
                     void *param_value,
                     size_t *param_value_size_ret)
{
    WARN_NOT_SUPPORTED(GetKernelInfo);
    return 0;
}

cl_int GetKernelArgInfo(cl_kernel kernel,
                        cl_uint arg_index,
                        KernelArgInfo param_name,
                        size_t param_value_size,
                        void *param_value,
                        size_t *param_value_size_ret)
{
    WARN_NOT_SUPPORTED(GetKernelArgInfo);
    return 0;
}

cl_int GetKernelWorkGroupInfo(cl_kernel kernel,
                              cl_device_id device,
                              KernelWorkGroupInfo param_name,
                              size_t param_value_size,
                              void *param_value,
                              size_t *param_value_size_ret)
{
    WARN_NOT_SUPPORTED(GetKernelWorkGroupInfo);
    return 0;
}

cl_int GetKernelSubGroupInfo(cl_kernel kernel,
                             cl_device_id device,
                             KernelSubGroupInfo param_name,
                             size_t input_value_size,
                             const void *input_value,
                             size_t param_value_size,
                             void *param_value,
                             size_t *param_value_size_ret)
{
    WARN_NOT_SUPPORTED(GetKernelSubGroupInfo);
    return 0;
}

cl_int WaitForEvents(cl_uint num_events, const cl_event *event_list)
{
    WARN_NOT_SUPPORTED(WaitForEvents);
    return 0;
}

cl_int GetEventInfo(cl_event event,
                    EventInfo param_name,
                    size_t param_value_size,
                    void *param_value,
                    size_t *param_value_size_ret)
{
    WARN_NOT_SUPPORTED(GetEventInfo);
    return 0;
}

cl_event CreateUserEvent(cl_context context, cl_int *errcode_ret)
{
    WARN_NOT_SUPPORTED(CreateUserEvent);
    return 0;
}

cl_int RetainEvent(cl_event event)
{
    WARN_NOT_SUPPORTED(RetainEvent);
    return 0;
}

cl_int ReleaseEvent(cl_event event)
{
    WARN_NOT_SUPPORTED(ReleaseEvent);
    return 0;
}

cl_int SetUserEventStatus(cl_event event, cl_int execution_status)
{
    WARN_NOT_SUPPORTED(SetUserEventStatus);
    return 0;
}

cl_int SetEventCallback(cl_event event,
                        cl_int command_exec_callback_type,
                        void(CL_CALLBACK *pfn_notify)(cl_event event,
                                                      cl_int event_command_status,
                                                      void *user_data),
                        void *user_data)
{
    WARN_NOT_SUPPORTED(SetEventCallback);
    return 0;
}

cl_int GetEventProfilingInfo(cl_event event,
                             ProfilingInfo param_name,
                             size_t param_value_size,
                             void *param_value,
                             size_t *param_value_size_ret)
{
    WARN_NOT_SUPPORTED(GetEventProfilingInfo);
    return 0;
}

cl_int Flush(cl_command_queue command_queue)
{
    WARN_NOT_SUPPORTED(Flush);
    return 0;
}

cl_int Finish(cl_command_queue command_queue)
{
    WARN_NOT_SUPPORTED(Finish);
    return 0;
}

cl_int EnqueueReadBuffer(cl_command_queue command_queue,
                         cl_mem buffer,
                         cl_bool blocking_read,
                         size_t offset,
                         size_t size,
                         void *ptr,
                         cl_uint num_events_in_wait_list,
                         const cl_event *event_wait_list,
                         cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueReadBuffer);
    return 0;
}

cl_int EnqueueReadBufferRect(cl_command_queue command_queue,
                             cl_mem buffer,
                             cl_bool blocking_read,
                             const size_t *buffer_origin,
                             const size_t *host_origin,
                             const size_t *region,
                             size_t buffer_row_pitch,
                             size_t buffer_slice_pitch,
                             size_t host_row_pitch,
                             size_t host_slice_pitch,
                             void *ptr,
                             cl_uint num_events_in_wait_list,
                             const cl_event *event_wait_list,
                             cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueReadBufferRect);
    return 0;
}

cl_int EnqueueWriteBuffer(cl_command_queue command_queue,
                          cl_mem buffer,
                          cl_bool blocking_write,
                          size_t offset,
                          size_t size,
                          const void *ptr,
                          cl_uint num_events_in_wait_list,
                          const cl_event *event_wait_list,
                          cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueWriteBuffer);
    return 0;
}

cl_int EnqueueWriteBufferRect(cl_command_queue command_queue,
                              cl_mem buffer,
                              cl_bool blocking_write,
                              const size_t *buffer_origin,
                              const size_t *host_origin,
                              const size_t *region,
                              size_t buffer_row_pitch,
                              size_t buffer_slice_pitch,
                              size_t host_row_pitch,
                              size_t host_slice_pitch,
                              const void *ptr,
                              cl_uint num_events_in_wait_list,
                              const cl_event *event_wait_list,
                              cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueWriteBufferRect);
    return 0;
}

cl_int EnqueueFillBuffer(cl_command_queue command_queue,
                         cl_mem buffer,
                         const void *pattern,
                         size_t pattern_size,
                         size_t offset,
                         size_t size,
                         cl_uint num_events_in_wait_list,
                         const cl_event *event_wait_list,
                         cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueFillBuffer);
    return 0;
}

cl_int EnqueueCopyBuffer(cl_command_queue command_queue,
                         cl_mem src_buffer,
                         cl_mem dst_buffer,
                         size_t src_offset,
                         size_t dst_offset,
                         size_t size,
                         cl_uint num_events_in_wait_list,
                         const cl_event *event_wait_list,
                         cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueCopyBuffer);
    return 0;
}

cl_int EnqueueCopyBufferRect(cl_command_queue command_queue,
                             cl_mem src_buffer,
                             cl_mem dst_buffer,
                             const size_t *src_origin,
                             const size_t *dst_origin,
                             const size_t *region,
                             size_t src_row_pitch,
                             size_t src_slice_pitch,
                             size_t dst_row_pitch,
                             size_t dst_slice_pitch,
                             cl_uint num_events_in_wait_list,
                             const cl_event *event_wait_list,
                             cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueCopyBufferRect);
    return 0;
}

cl_int EnqueueReadImage(cl_command_queue command_queue,
                        cl_mem image,
                        cl_bool blocking_read,
                        const size_t *origin,
                        const size_t *region,
                        size_t row_pitch,
                        size_t slice_pitch,
                        void *ptr,
                        cl_uint num_events_in_wait_list,
                        const cl_event *event_wait_list,
                        cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueReadImage);
    return 0;
}

cl_int EnqueueWriteImage(cl_command_queue command_queue,
                         cl_mem image,
                         cl_bool blocking_write,
                         const size_t *origin,
                         const size_t *region,
                         size_t input_row_pitch,
                         size_t input_slice_pitch,
                         const void *ptr,
                         cl_uint num_events_in_wait_list,
                         const cl_event *event_wait_list,
                         cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueWriteImage);
    return 0;
}

cl_int EnqueueFillImage(cl_command_queue command_queue,
                        cl_mem image,
                        const void *fill_color,
                        const size_t *origin,
                        const size_t *region,
                        cl_uint num_events_in_wait_list,
                        const cl_event *event_wait_list,
                        cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueFillImage);
    return 0;
}

cl_int EnqueueCopyImage(cl_command_queue command_queue,
                        cl_mem src_image,
                        cl_mem dst_image,
                        const size_t *src_origin,
                        const size_t *dst_origin,
                        const size_t *region,
                        cl_uint num_events_in_wait_list,
                        const cl_event *event_wait_list,
                        cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueCopyImage);
    return 0;
}

cl_int EnqueueCopyImageToBuffer(cl_command_queue command_queue,
                                cl_mem src_image,
                                cl_mem dst_buffer,
                                const size_t *src_origin,
                                const size_t *region,
                                size_t dst_offset,
                                cl_uint num_events_in_wait_list,
                                const cl_event *event_wait_list,
                                cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueCopyImageToBuffer);
    return 0;
}

cl_int EnqueueCopyBufferToImage(cl_command_queue command_queue,
                                cl_mem src_buffer,
                                cl_mem dst_image,
                                size_t src_offset,
                                const size_t *dst_origin,
                                const size_t *region,
                                cl_uint num_events_in_wait_list,
                                const cl_event *event_wait_list,
                                cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueCopyBufferToImage);
    return 0;
}

void *EnqueueMapBuffer(cl_command_queue command_queue,
                       cl_mem buffer,
                       cl_bool blocking_map,
                       cl_map_flags map_flags,
                       size_t offset,
                       size_t size,
                       cl_uint num_events_in_wait_list,
                       const cl_event *event_wait_list,
                       cl_event *event,
                       cl_int *errcode_ret)
{
    WARN_NOT_SUPPORTED(EnqueueMapBuffer);
    return 0;
}

void *EnqueueMapImage(cl_command_queue command_queue,
                      cl_mem image,
                      cl_bool blocking_map,
                      cl_map_flags map_flags,
                      const size_t *origin,
                      const size_t *region,
                      size_t *image_row_pitch,
                      size_t *image_slice_pitch,
                      cl_uint num_events_in_wait_list,
                      const cl_event *event_wait_list,
                      cl_event *event,
                      cl_int *errcode_ret)
{
    WARN_NOT_SUPPORTED(EnqueueMapImage);
    return 0;
}

cl_int EnqueueUnmapMemObject(cl_command_queue command_queue,
                             cl_mem memobj,
                             void *mapped_ptr,
                             cl_uint num_events_in_wait_list,
                             const cl_event *event_wait_list,
                             cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueUnmapMemObject);
    return 0;
}

cl_int EnqueueMigrateMemObjects(cl_command_queue command_queue,
                                cl_uint num_mem_objects,
                                const cl_mem *mem_objects,
                                cl_mem_migration_flags flags,
                                cl_uint num_events_in_wait_list,
                                const cl_event *event_wait_list,
                                cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueMigrateMemObjects);
    return 0;
}

cl_int EnqueueNDRangeKernel(cl_command_queue command_queue,
                            cl_kernel kernel,
                            cl_uint work_dim,
                            const size_t *global_work_offset,
                            const size_t *global_work_size,
                            const size_t *local_work_size,
                            cl_uint num_events_in_wait_list,
                            const cl_event *event_wait_list,
                            cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueNDRangeKernel);
    return 0;
}

cl_int EnqueueNativeKernel(cl_command_queue command_queue,
                           void(CL_CALLBACK *user_func)(void *),
                           void *args,
                           size_t cb_args,
                           cl_uint num_mem_objects,
                           const cl_mem *mem_list,
                           const void **args_mem_loc,
                           cl_uint num_events_in_wait_list,
                           const cl_event *event_wait_list,
                           cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueNativeKernel);
    return 0;
}

cl_int EnqueueMarkerWithWaitList(cl_command_queue command_queue,
                                 cl_uint num_events_in_wait_list,
                                 const cl_event *event_wait_list,
                                 cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueMarkerWithWaitList);
    return 0;
}

cl_int EnqueueBarrierWithWaitList(cl_command_queue command_queue,
                                  cl_uint num_events_in_wait_list,
                                  const cl_event *event_wait_list,
                                  cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueBarrierWithWaitList);
    return 0;
}

cl_int EnqueueSVMFree(cl_command_queue command_queue,
                      cl_uint num_svm_pointers,
                      void *svm_pointers[],
                      void(CL_CALLBACK *pfn_free_func)(cl_command_queue queue,
                                                       cl_uint num_svm_pointers,
                                                       void *svm_pointers[],
                                                       void *user_data),
                      void *user_data,
                      cl_uint num_events_in_wait_list,
                      const cl_event *event_wait_list,
                      cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueSVMFree);
    return 0;
}

cl_int EnqueueSVMMemcpy(cl_command_queue command_queue,
                        cl_bool blocking_copy,
                        void *dst_ptr,
                        const void *src_ptr,
                        size_t size,
                        cl_uint num_events_in_wait_list,
                        const cl_event *event_wait_list,
                        cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueSVMMemcpy);
    return 0;
}

cl_int EnqueueSVMMemFill(cl_command_queue command_queue,
                         void *svm_ptr,
                         const void *pattern,
                         size_t pattern_size,
                         size_t size,
                         cl_uint num_events_in_wait_list,
                         const cl_event *event_wait_list,
                         cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueSVMMemFill);
    return 0;
}

cl_int EnqueueSVMMap(cl_command_queue command_queue,
                     cl_bool blocking_map,
                     cl_map_flags flags,
                     void *svm_ptr,
                     size_t size,
                     cl_uint num_events_in_wait_list,
                     const cl_event *event_wait_list,
                     cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueSVMMap);
    return 0;
}

cl_int EnqueueSVMUnmap(cl_command_queue command_queue,
                       void *svm_ptr,
                       cl_uint num_events_in_wait_list,
                       const cl_event *event_wait_list,
                       cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueSVMUnmap);
    return 0;
}

cl_int EnqueueSVMMigrateMem(cl_command_queue command_queue,
                            cl_uint num_svm_pointers,
                            const void **svm_pointers,
                            const size_t *sizes,
                            cl_mem_migration_flags flags,
                            cl_uint num_events_in_wait_list,
                            const cl_event *event_wait_list,
                            cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueSVMMigrateMem);
    return 0;
}

void *GetExtensionFunctionAddressForPlatform(cl_platform_id platform, const char *func_name)
{
    return GetExtensionFunctionAddress(func_name);
}

cl_int SetCommandQueueProperty(cl_command_queue command_queue,
                               cl_command_queue_properties properties,
                               cl_bool enable,
                               cl_command_queue_properties *old_properties)
{
    return static_cast<CommandQueue *>(command_queue)
        ->setProperty(properties, enable, old_properties);
}

cl_mem CreateImage2D(cl_context context,
                     cl_mem_flags flags,
                     const cl_image_format *image_format,
                     size_t image_width,
                     size_t image_height,
                     size_t image_row_pitch,
                     void *host_ptr,
                     cl_int *errcode_ret)
{
    return static_cast<Context *>(context)->createImage2D(
        flags, image_format, image_width, image_height, image_row_pitch, host_ptr, errcode_ret);
}

cl_mem CreateImage3D(cl_context context,
                     cl_mem_flags flags,
                     const cl_image_format *image_format,
                     size_t image_width,
                     size_t image_height,
                     size_t image_depth,
                     size_t image_row_pitch,
                     size_t image_slice_pitch,
                     void *host_ptr,
                     cl_int *errcode_ret)
{
    return static_cast<Context *>(context)->createImage3D(
        flags, image_format, image_width, image_height, image_depth, image_row_pitch,
        image_slice_pitch, host_ptr, errcode_ret);
}

cl_int EnqueueMarker(cl_command_queue command_queue, cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueMarker);
    return 0;
}

cl_int EnqueueWaitForEvents(cl_command_queue command_queue,
                            cl_uint num_events,
                            const cl_event *event_list)
{
    WARN_NOT_SUPPORTED(EnqueueWaitForEvents);
    return 0;
}

cl_int EnqueueBarrier(cl_command_queue command_queue)
{
    WARN_NOT_SUPPORTED(EnqueueBarrier);
    return 0;
}

cl_int UnloadCompiler()
{
    WARN_NOT_SUPPORTED(UnloadCompiler);
    return 0;
}

void *GetExtensionFunctionAddress(const char *func_name)
{
    if (func_name == nullptr)
    {
        return nullptr;
    }
    const ProcTable &procTable = GetProcTable();
    const auto it              = procTable.find(func_name);
    return it != procTable.cend() ? it->second : nullptr;
}

cl_command_queue CreateCommandQueue(cl_context context,
                                    cl_device_id device,
                                    cl_command_queue_properties properties,
                                    cl_int *errcode_ret)
{
    return static_cast<Context *>(context)->createCommandQueue(device, properties, errcode_ret);
}

cl_sampler CreateSampler(cl_context context,
                         cl_bool normalized_coords,
                         AddressingMode addressing_mode,
                         FilterMode filter_mode,
                         cl_int *errcode_ret)
{
    return static_cast<Context *>(context)->createSampler(normalized_coords, addressing_mode,
                                                          filter_mode, errcode_ret);
}

cl_int EnqueueTask(cl_command_queue command_queue,
                   cl_kernel kernel,
                   cl_uint num_events_in_wait_list,
                   const cl_event *event_wait_list,
                   cl_event *event)
{
    WARN_NOT_SUPPORTED(EnqueueTask);
    return 0;
}

}  // namespace cl
