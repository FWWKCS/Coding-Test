antenna = int(input())
eyes = int(input())

# TroyMartian : 최소 3개의 안테나, 최대 4개의 눈
# VladSaturnian : 최대 6개의 안테나, 최소 2개의 눈
# GraemeMercurian : 최대 2개의 안테나, 최대 3개의 눈

if antenna >= 3 and eyes <= 4 :
    print('TroyMartian')
if antenna <= 6 and eyes >= 2 :
    print('VladSaturnian')
if antenna <= 2 and eyes <= 3 :
    print('GraemeMercurian')