class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Sort the vectors (if they are not already sorted)
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        // Vector to store the intersection
        std::vector<int> intersection;

        // Perform the intersection
        std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(),
                              nums2.end(), std::back_inserter(intersection));


        return intersection;
    }
};