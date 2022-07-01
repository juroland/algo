template <typename T>
class Vector
{
  public:
    using value_type = T; // Alias
  private:
    int size_;
    value_type *elem_;
  public:
    Vector(int size);
    ~Vector();
    value_type &operator[](int i);
    const value_type &operator[](int i) const;
    int size() const;
};
#include "vector_generique_impl.hpp"