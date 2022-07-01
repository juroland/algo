class Vector
{
    int size_;
    double *elem_;

  public:
    Vector(int size);

    ~Vector();

    double &operator[](int i);
    const double &operator[](int i) const;

    int size() const;
};