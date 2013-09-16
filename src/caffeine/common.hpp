#ifndef CAFFEINE_COMMON_HPP_
#define CAFFEINE_COMMON_HPP_

#include <boost/shared_ptr.hpp>
#include <cublas_v2.h>
#include <glog/logging.h>
#include <mkl_vsl.h>

#include "driver_types.h"

#define CUDA_CHECK(condition) CHECK_EQ((condition), cudaSuccess)
#define CUBLAS_CHECK(condition) CHECK_EQ((condition), CUBLAS_STATUS_SUCCESS)
#define VSL_CHECK(condition) CHECK_EQ((condition), VSL_STATUS_OK)

namespace caffeine {

// We will use the boost shared_ptr instead of the new C++11 one mainly
// because cuda does not work (at least now) well with C++11 features.
using boost::shared_ptr;

// For backward compatibility we will just use 512 threads per block
const int CAFFEINE_CUDA_NUM_THREADS = 512;

// A singleton class to hold common caffeine stuff, such as the handler that
// caffeine is going to use for cublas.
class Caffeine {
 public:
  ~Caffeine();
  static Caffeine& Get();
  enum Brew { CPU, GPU };
  enum Phase { TRAIN, TEST};

  // The getters for the variables. 
  static cublasHandle_t cublas_handle();
  static VSLStreamStatePtr vsl_stream();
  static Brew mode();
  static Phase phase();
  // The setters for the variables
  static void set_mode(Brew mode);
  static void set_phase(Phase phase);
 private:
  Caffeine();
  static shared_ptr<Caffeine> singleton_;
  cublasHandle_t cublas_handle_;
  VSLStreamStatePtr vsl_stream_;
  Brew mode_;
  Phase phase_;
};

}  // namespace caffeine

#endif  // CAFFEINE_COMMON_HPP_