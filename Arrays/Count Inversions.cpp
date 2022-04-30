///T.C -O(nlogn)
///S.C- o(n)
class Solution{
  private:
long long int merge(long long arr[],long long temp[],long long  l,long long  mid,long long  h)
     {
         int k=l;
         int i=l;
         int j=mid+1;
         long long int  inv=0;
         while((i<=mid) && (j<=h))
         {
             if(arr[i]<=arr[j])
             temp[k++]=arr[i++];
             else{
                 inv+=(mid+1)-i;
                 temp[k++]=arr[j++];
             }
         } 
         while(i<=mid)
         temp[k++]=arr[i++];
         while(j<=h)
         temp[k++]=arr[j++];
         for(int i=l;i<=h;i++)
         arr[i]=temp[i];
         return inv;
     }
    long long int  mergesort(long long arr[],long long temp[],long long  l,long long  h)
    {
        long long int inv=0;
        if(l<h)
        {
            long long mid=(l+h)/2;
            inv+=mergesort(arr,temp,l,mid);
            inv+=mergesort(arr,temp,mid+1,h);
           inv+= merge(arr,temp,l,mid,h);
        }
        return inv;
    } 
  public:
    long long int inversionCount(long long arr[], long long N)
    { 
        long long temp[N]={0};
          long long int count=0;
       count= mergesort(arr,temp,0,N-1);
       return count;
        
    }

};
