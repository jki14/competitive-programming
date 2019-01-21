def DanceBattle(energy, skills):
    #TODO: check energy and skills is valid (engergy > 0, skills[i] > 0)
    skills = sorted(skills)
    honor = 0
    num_team = len(skills)
    recruited = num_team
    for i in xrange(num_team):
        if i == recruited:
            break
        if skills[i] < energy:
            energy -= skills[i]
            honor += 1
        elif honor > 0 and recruited - 1 > i:
            energy += skills[recruited - 1] - skills[i]
            recruited -= 1
        else:
            break
    return honor

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        e, n = [int(j) for j in raw_input().strip().split()]
        s = [int(j) for j in raw_input().strip().split()]
        print('Case #%d: %d' % (i + 1, DanceBattle(e, s)))

if __name__ == '__main__':
    main()
