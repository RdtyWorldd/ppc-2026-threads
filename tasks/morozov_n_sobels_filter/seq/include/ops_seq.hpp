#pragma once

#include <cstddef>

#include "morozov_n_sobels_filter/common/include/common.hpp"
#include "task/include/task.hpp"

namespace morozov_n_sobels_filter {

class MorozovNSobelsFilterSEQ : public BaseTask {
 public:
  static constexpr ppc::task::TypeOfTask GetStaticTypeOfTask() {
    return ppc::task::TypeOfTask::kSEQ;
  }
  explicit MorozovNSobelsFilterSEQ(const InType &in);

 private:
  bool ValidationImpl() override;
  bool PreProcessingImpl() override;
  bool RunImpl() override;
  bool PostProcessingImpl() override;

  void Filter(const Image& img);
  uint8_t CalculateNewPixelColor(const Image& img, size_t x, size_t y);

  const std::array<std::array<int, 3>, 3> _kKernelX = {std::array<int, 3>{-1, 0, 1}, std::array<int, 3>{-2, 0, 2},
                                                   std::array<int, 3>{-1, 0, 1}};

  const std::array<std::array<int, 3>, 3> _kKernelY = {std::array<int, 3>{-1, -2, -1}, std::array<int, 3>{0, 0, 0},
                                                   std::array<int, 3>{1, 2, 1}};
  Image result_image_;
};

}  // namespace morozov_n_sobels_filter
