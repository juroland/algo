#include <memory>

class Vector
{
    int size_;
    std::unique_ptr<double[]> elem_;

  public:
    Vector(int size);

    ~Vector() = default;

    double &operator[](int i);
    const double &operator[](int i) const;

    int size() const;
};