throttle = 70
brake = 0

while(True):
    print("throttle", throttle)
    print("brake", brake)
    speed = input()
    speed = speed.split(" ")
    speed = float(speed[1])
    distance = input()
    distance = distance.split(" ")
    if(float(distance[1]) >= 1000):
        throttle = 0
        brake = 100
    time = input()
    speedlimit = input()
    speedlimit = speedlimit.split(" ")
    nextSpeedLimit = float(speedlimit[3])
    actualSpeedLimit = float(speedlimit[1])
    nextDistance = float(speedlimit[2])
    if nextDistance < 40 and nextSpeedLimit > 0:
        if (nextSpeedLimit < speed):
            brake = 80
            throttle = 0
        elif nextSpeedLimit - 10 <= speed:
            throttle = 10
            brake = 0
    if nextDistance < 70 and nextSpeedLimit > 0:
        if nextSpeedLimit - 10 <= speed:
            throttle = 5
            brake = 0
        elif throttle > 20:
            throttle = 5
    elif nextDistance > 70 or nextSpeedLimit >= 0:
        if(actualSpeedLimit - 10 <= speed):
            throttle = 5
            brake = 0
        if speed + 1 >= actualSpeedLimit:
            throttle = 0
            brake = 5
        elif actualSpeedLimit - 15 > speed:
            throttle = 15
            brake = 0
    update = input()
