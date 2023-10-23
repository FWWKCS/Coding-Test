info = ['SHIP NAME','CLASS','DEPLOYMENT','IN SERVICE']

ship_name = ['N2 Bomber','J-Type 327','NX Cruiser','N1 Starfighter','Royal Cruiser']
ship_class = ['Heavy Fighter','Light Combat','Medium Fighter','Medium Fighter','Light Combat']
deployment = ['Limited','Unlimited','Limited','Unlimited','Limited']
in_service = [21, 1, 18, 25, 4]

print(f'{info[0]:<15s}{info[1]:<15s}{info[2]:<11s}{info[3]:<10s}')
for k in range(5):
    print(f'{ship_name[k]:<15s}{ship_class[k]:<15s}{deployment[k]:<11s}{str(in_service[k]):<10s}')