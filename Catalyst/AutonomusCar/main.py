throttle = 30
brake = 0


def keepInRange(throttle, brake, actualSpeedLimit):
    if(actualSpeedLimit - 5 <= speed):
        throttle = 5
        brake = 0
    if speed + 1 >= actualSpeedLimit:
        throttle = 0
        brake = 5
    # elif actualSpeedLimit - 15 > speed:
    #     throttle = 100
    #     brake = 0
    return throttle, brake


ok = 1
while(True):
    print("throttle", throttle)
    print("brake", brake)
    speed = input()
    speed = speed.split(" ")
    speed = float(speed[1])
    distance = input()
    distance = distance.split(" ")
    if(float(distance[1]) >= 1200):
        throttle = 0
        brake = 100
    time = input()
    speedlimit = input()
    speedlimit = speedlimit.split(" ")
    nextSpeedLimit = float(speedlimit[3])
    actualSpeedLimit = float(speedlimit[1])
    nextDistance = float(speedlimit[2])
    traficLight = input()
    light = "no"
    nextTraficLightSec = -1
    nextTraficLightDist = -1
    traficLight = traficLight.split(" ")
    if len(traficLight) >= 4:
        nextTraficLightDist = float(traficLight[1])
        light = traficLight[2]
        nextTraficLightSec = float(traficLight[3])
    if(nextTraficLightDist != -1):
        speedToZero = speed / 21
        travel = speedToZero * 5.8
        if(light != "Green"):
            if(nextTraficLightDist - 15 < travel):
                brake = 100
                throttle = 0
                ok = 1
        if(light == "Green"):
            if(speedToZero > nextTraficLightSec and nextTraficLightDist - 15 < travel):
                brake = 40
                throttle = 0
                ok = 1
            else:
                throttle = 40
                brake = 0
                ok = 0
        if ok == 0:
            throttle, brake = keepInRange(throttle, brake, actualSpeedLimit)
    update = input()
