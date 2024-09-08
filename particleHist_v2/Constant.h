#ifndef Constant_h
#define Constant_h

class Constant{

public:
    constexpr static double massPion    = 0.1395706;   // GeV/c^2
    constexpr static double massProton  = 0.938272;    // GeV/c^2
    constexpr static double massK0      = 0.497611;    // GeV/c^2
    constexpr static double massLambda0 = 1.115683;    // GeV/c^2
};

//Devono essere static di modo da poter essere viste anche in altre occorrenze!
//constexpr perchè è un oggetto non modificabile conosciuto a run-time
#endif