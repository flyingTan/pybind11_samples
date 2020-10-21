#include <torch/torch.h>
#include <iostream> 

at::Tensor nms_cuda(const at::Tensor& dets, const float threshold);

int main() {
  torch::Tensor tensor = torch::randn({3, 5}).cuda();

  std::cout <<"The tensor is: "<< tensor << std::endl;

  torch::Tensor res = nms_cuda(tensor, 0.5);
  std::cout<<"The result is: "<< res<<std::endl;
}
