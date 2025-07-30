#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

typedef long long int lld;

class Solution {
public:
    // Define the maximum number of bits to consider. 34 is safe for 32-bit integers.
    const static int MAXB = 34;
    // A mask to ensure we only work with the relevant 31 bits for positive integers.
    const long long FULL_MASK = (1LL << 31) - 1;
    
    // The vector to store the linear basis.
    std::vector<lld> basis;

    /**
     * @brief Builds a linear basis for a set of numbers, considering only specific bits.
     * @param candidates The list of numbers (from sets A and C) to build the basis from.
     * @param masked_val A bitmask (~s) to focus the basis construction on the "free" bits.
     * * The goal is to find a number 'x' in the span of `candidates` that maximizes `x & masked_val`.
     * This function builds a basis for the values `v & masked_val`, which allows us to
     * greedily construct the optimal `x & masked_val`.
     */
    void buildBasis(const std::vector<int>& candidates, lld masked_val) {
        basis = std::vector<lld>(MAXB, 0LL);
        for (const int& v : candidates) {
            lld val_for_basis = (lld)v & masked_val;
            // Reduce the value by the existing basis vectors (Gaussian elimination).
            for (int i = MAXB - 1; i >= 0; --i) {
                if (!((val_for_basis >> i) & 1)) continue;
                if (basis[i] == 0LL) {
                    basis[i] = val_for_basis;
                    break;
                }
                val_for_basis ^= basis[i];
            }
        }
    }

    long long maximizeXorAndXor(std::vector<int>& nums) {
        int n = nums.size();
        int max_mask = (1 << n);
        lld max_result = 0LL;

        // 1. Iterate through all 2^n possible subsets for subsequence B.
        // The integer 'mask' acts as a bitmask to represent the subset.
        for (int mask = 0; mask < max_mask; ++mask) {
            std::vector<int> set_A_C;
            lld and_B = -1; // Represents all bits set to 1 initially.

            // 2. Partition nums into B and (A U C) based on the current mask.
            for (int j = 0; j < n; ++j) {
                if ((mask >> j) & 1) { // If j-th bit is set, nums[j] is in B.
                    if (and_B == -1) {
                        and_B = (lld)nums[j];
                    } else {
                        and_B &= (lld)nums[j];
                    }
                } else { // Otherwise, nums[j] is in the combined set for A and C.
                    set_A_C.push_back(nums[j]);
                }
            }

            // If B was empty, its AND value is 0.
            if (and_B == -1) and_B = 0LL;

            // 3. Solve the subproblem: Maximize XOR(A) + XOR(C).
            // Let s = XOR(A U C) and x = XOR(A). We want to maximize x + (s^x).
            // Using the identity a+b = (a^b) + 2*(a&b), we can show:
            // x + (s^x) = s + 2*(x & ~s)
            // So, we need to find an x in the span of set_A_C that maximizes (x & ~s).

            lld s = 0LL; // This is `s`, the XOR sum of all elements in A and C.
            for (int val : set_A_C) {
                s ^= (lld)val;
            }

            // This is `~s`, the mask for the "free" bits we want to maximize.
            lld free_bits_mask = (~s) & FULL_MASK;

            // 4. Build a basis for `x & ~s`.
            buildBasis(set_A_C, free_bits_mask);

            // 5. Greedily construct the `x` that maximizes `x & ~s`.
            // We start with x=0 and try to flip bits from MSB to LSB.
            lld max_x_and_mask = 0LL;
            for (int j = MAXB - 1; j >= 0; --j) {
                // If we can get a larger value by including basis[j], we do.
                // This works because the basis is constructed to be "triangular".
                if ((max_x_and_mask ^ basis[j]) > max_x_and_mask) {
                    max_x_and_mask ^= basis[j];
                }
            }
            
            // Note: The original solution had `(maxXOR^B[j])&allXORInv`.
            // The `& allXORInv` is redundant because the basis was already built with that mask.
            // The simplified `(val ^ B[j]) > val` is equivalent and clearer.

            // 6. Calculate the total value for this partition and update the overall max.
            max_result = std::max(max_result, and_B + s + 2LL * max_x_and_mask);
        }
        return max_result;
    }
};