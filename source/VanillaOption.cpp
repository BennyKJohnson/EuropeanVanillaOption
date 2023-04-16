#include "VanillaOption.h"
#include "cmath"

VanillaOption::VanillaOption()
{
}

VanillaOption::VanillaOption(const double strikePrice, const double riskFreeRate, const double maturityTime, const double underlyingPrice, const double volatility) {
	_strikePrice = strikePrice;
	_riskFreeRate = riskFreeRate;
	_maturityTime = maturityTime;
	_underlyingPrice = underlyingPrice;
	_volatility = volatility;
}

void VanillaOption::copy(const VanillaOption& rhs) {
	_strikePrice = rhs.getStrikePrice();
	_riskFreeRate = rhs.getRiskFreeRate();
	_maturityTime = rhs.getMaturityTime();
	_underlyingPrice = rhs.getUnderlyingPrice();
	_volatility = rhs.getVolatility();
}

VanillaOption& VanillaOption::operator=(const VanillaOption& rhs) {
	if (this == &rhs)
		return *this;
	copy(rhs);

	return *this;
}

double VanillaOption::getStrikePrice() const {
	return _strikePrice;
}

double VanillaOption::getRiskFreeRate() const {
	return _riskFreeRate;
}

double VanillaOption::getMaturityTime() const {
	return _maturityTime;
}

double VanillaOption::getUnderlyingPrice() const {
	return _underlyingPrice;
}

double VanillaOption::getVolatility() const {
	return _volatility;
}

double VanillaOption::getD1() const {
	double sigmaSquared = _volatility * sqrt(_maturityTime);
	return (log(_underlyingPrice / _strikePrice) + (_riskFreeRate + sigmaSquared * sigmaSquared * 0.5) * _maturityTime) / sigmaSquared;
}

double VanillaOption::getD2() const {
	return getD1() - _volatility * sqrt(_maturityTime);
}

double VanillaOption::calculateCallPrice() const {
	return _underlyingPrice * VanillaOption::getStandardNormalCDF(getD1()) - _strikePrice * exp(-_riskFreeRate * _maturityTime) * VanillaOption::getStandardNormalCDF(getD2());
}

double VanillaOption::calculatePutPrice() const {
	return _strikePrice * exp(-_riskFreeRate * _maturityTime) * VanillaOption::getStandardNormalCDF(-getD2()) - _underlyingPrice * VanillaOption::getStandardNormalCDF(-getD1());
}
