#ifndef _VANILLA_OPTION_H
#define _VANILLA_OPTION_H

class VanillaOption {
public:
VanillaOption();

VanillaOption(const double strikePrice, const double riskFreeRate, const double maturityTime, const double underlyingPrice, const double volatility);

double getStrikePrice() const;

double getRiskFreeRate() const;

double getMaturityTime() const;

double getUnderlyingPrice() const;

double getVolatility() const;

double getD1() const;

double getD2() const;

double calculateCallPrice() const;

double calculatePutPrice() const;

static double getStandardNormalCDF(double z) {
	return 0.5 * (1 + erf(z / sqrt(2)));
}

void copy(const VanillaOption& rhs);


private:
void init();
double _strikePrice; // K

double _riskFreeRate; // r

double _maturityTime; // T

double _underlyingPrice; // S

double _volatility; // sigma
};

#endif