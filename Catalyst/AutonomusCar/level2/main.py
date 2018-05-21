throttle = 100
brake = 0

while(True):
    print("throttle", throttle)
    print("brake", brake)
    speed = input()
    speed = speed.split(" ")
    speed = float(speed[1])
    distance = input()
    distance = distance.split(" ")
    if(float(distance[1]) >= 1500):
        throttle = 0
        brake = 100
    time = input()
    speedlimit = input()
    speedlimit = speedlimit.split(" ")
    nextSpeedLimit = float(speedlimit[3])
    actualSpeedLimit = float(speedlimit[1])
    nextDistance = float(speedlimit[2])
    if nextDistance < 100 and nextSpeedLimit > 0:
        if (nextSpeedLimit < speed):
            brake = 100
            throttle = 0
        if(nextSpeedLimit-10 >= speed):
            throttle = 5
            brake = 0
    else:
        if(actualSpeedLimit - 10 <= speed):
            throttle = 5
            brake = 0
        if speed + 5 >= actualSpeedLimit:
            throttle = 10
            brake = 10
        elif actualSpeedLimit - 15 > speed:
            throttle = 100
            brake = 0
    update = input()
