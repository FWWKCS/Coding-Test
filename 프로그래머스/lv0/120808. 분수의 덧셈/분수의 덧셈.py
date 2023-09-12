def getGCD(a, b) :
    if a % b == 0 : return b
    return getGCD(b, a%b)

def solution(numer1, denom1, numer2, denom2):
    answer = []
    GCD = getGCD(denom1, denom2)
    LCM = denom1*denom2 // GCD
    
    resultDenom = LCM
    resultNumer = (numer1 * (LCM // denom1)) + (numer2 * (LCM // denom2))
    
    resultGCD = getGCD(resultNumer, resultDenom)
    
    answer = [resultNumer // resultGCD, resultDenom // resultGCD]
    
    return answer