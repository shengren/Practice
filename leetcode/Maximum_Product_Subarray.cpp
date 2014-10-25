class Solution {
 public:
  int maxProduct(int A[], int n) {
    // Use the maximum element to initialize max_product_.
    max_product_ = A[0];
    for (int i = 1; i < n; ++i) {
      if (max_product_ < A[i]) max_product_ = A[i];
    }

    // For each contiguous subarray without zeros, find its max product.
    int k = 0;
    for (int i = 0; i < n; ++i) {
      if (A[i] == 0) {
        if (k < i) FindMaxProduct(A, k, i);
        k = i + 1;
      }
    }
    if (k < n) FindMaxProduct(A, k, n);  // last subarray

    return max_product_;
  }

 private:
  void FindMaxProduct(const int *A, int a, int b) {
    bool had_first_negative = false;
    int until_first_negative;
    int idx_first_negative;

    // Progressively compute the product from the first element to the last
    // element and keep updating max_product_ using the partial products.
    int p = 1;
    for (int i = a; i < b; ++i) {
      p *= A[i];
      if (max_product_ < p) max_product_ = p;
      if (A[i] < 0 && !had_first_negative) {
        had_first_negative = true;
        until_first_negative = p;
        idx_first_negative = i;
      }
    }

    // If the final product is negative, remove the first negative element and
    // the elements before it and then update max_product_. The partial product
    // excluding the last negative element and the elements after it has been
    // covered by the previous loop. Removing more than one negative element
    // will not yield a larger product.
    if (p < 0 && idx_first_negative < b - 1) {
      p /= until_first_negative;
      if (max_product_ < p) max_product_ = p;
    }
  }

  int max_product_;
};
