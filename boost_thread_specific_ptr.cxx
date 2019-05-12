#include <boost/thread/tss.hpp>
 struct tss_test
 {
     class Cache 
     {
         public :
         Cache():validationLayer{nullptr},
         validationSteps{0},
         validationPhi{0.},
         validationEta{0.},
         accumulatedElossSigma{0.}{
         }
         const double*              validationLayer{nullptr};     //!< layer in the current validation setp
         int                         validationSteps{0};           //!< number of validation steps
         double                      validationPhi{0.};            //!< theta
         double                      validationEta{0.};            //!< eta
         double                      accumulatedElossSigma{0.};    //!< Sigma of the eloss accumulated so far in the extrapolation. Used in Landau mode
     };
     mutable boost::thread_specific_ptr<Cache> m_cache_tls;
     Cache& getTLSCache() const{ 
       Cache* cache = m_cache_tls.get();
       if (!cache) {
        cache = new Cache();
        m_cache_tls.reset( cache );
       }
       return *cache; 
     }
 };

 tss_test::Cache& fun(){

    tss_test test;
    tss_test::Cache& foo= test.getTLSCache();
    return foo;
 }

