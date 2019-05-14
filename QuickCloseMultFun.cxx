#include <cstdlib>
#include <utility>

typedef float * __restrict__ floatPtrRestrict ;
typedef int * __restrict__ intPtrRestrict ;

std::pair<int, int>  findMinimumIndex( const floatPtrRestrict distancesIn, 
                                       const int n) 
{

  float *distances = (float*)__builtin_assume_aligned(distancesIn, 32);
     int mini  = 0; 
     int mini2 = -1;
    for( int i = 0; i < n; ++i ){
     if( distances[ i ] < distances[mini] ){
       //min2 is now the previous one
       mini2 = mini;
       //mini is the new one
       mini  = i;
     }
   }
   return  std::make_pair(mini, mini2);
} 

std::pair<int, int>  findMinimumIndex1( const floatPtrRestrict distancesIn, 
                                       const size_t n) 
{
float *distances = (float*)__builtin_assume_aligned(distancesIn, sizeof(float));
     size_t mini  = 0; 
     size_t mini2 = -1;
     float minDistance=1e12;
 for( size_t i = 0; i < n; ++i ){
     if( distances[ i ] < minDistance ){
       //new min distance
       minDistance =distances[i];
       //min2 is now the previous one
       mini2 = mini;
       //mini is the new one
       mini  = i;
     }
   }
   return  std::make_pair(mini, mini2);
} 
