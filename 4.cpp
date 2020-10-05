class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size(),start=0,end,mid,mid2;
        if(n>m){
            return findMedianSortedArrays(nums2,nums1);
        }
        end=n;
        mid=(start+end)/2;
        int nM,nm,MM,Mm;
        while(start<=end){
            mid=(start+end)/2;
            mid2=(n+1+m)/2-mid;
            nM=(mid==0)?INT_MIN:nums1[mid-1];
            nm=(mid==n)?INT_MAX:nums1[mid];
            MM=(mid2==0)?INT_MIN:nums2[mid2-1];
            Mm=(mid2==m)?INT_MAX:nums2[mid2];
            
            if(max(nM,MM)<=min(nm,Mm)){
                if((n+m)%2)
                    return (double)max(nM,MM);
                else
                    return ((double)max(nM,MM)+(double)min(nm,Mm))/2;
            }
            else{
                if(MM>nM){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return 0.0;
    }
};
