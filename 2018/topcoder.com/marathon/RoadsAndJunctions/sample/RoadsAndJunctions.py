class RoadsAndJunctions:
    def buildJunctions(self, S, cities, junctionCost, failureProbability):
        # store number of cities for building the roads
        self.NC = len(cities) // 2
        # build one junction at (0,0)
        return [0, 0]
    def buildRoads(self, junctionStatus):
        # build a road from the single junction to each city
        # (we assume that it was built, but don't check it)
        ret = [];
        for i in range(self.NC):
            ret.append(self.NC)
            ret.append(i)
        return ret

# -------8<------- end of solution submitted to the website -------8<-------

import sys
S = int(raw_input())
C = int(raw_input())
cities = []
for i in range(C):
    cities.append(int(raw_input()))
junctionCost = float(raw_input())
failureProbability = float(raw_input())

rj = RoadsAndJunctions()
ret = rj.buildJunctions(S, cities, junctionCost, failureProbability)

print len(ret)
for num in ret:
    print num
sys.stdout.flush()

J = int(raw_input())
junctionStatus = []
for i in range(J):
    junctionStatus.append(int(raw_input()))

ret = rj.buildRoads(junctionStatus)
print len(ret)
for num in ret:
    print num
