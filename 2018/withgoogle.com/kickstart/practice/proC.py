def SortAScrambledItinerary(tickets):
    #TODO: check if tickets is valid
    nextCity = {}
    destset = set()
    for ticket in tickets:
        if ticket[0] not in nextCity:
            nextCity[ticket[0]] = ticket[1]
            if ticket[1] not in destset:
                destset.add(ticket[1])
            else:
                raise ValueError
        else:
            raise ValueError
    homeCity = None
    for departureCity in nextCity.keys():
        if departureCity not in destset:
            if homeCity is None:
                homeCity = departureCity
            else:
                raise ValueError
    if homeCity is not None:
        foo = ''
        while homeCity in nextCity:
            foo += ' %s-%s' % (homeCity, nextCity[homeCity])
            homeCity = nextCity[homeCity]
        return foo
    else:
        return None

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        n = int(raw_input().strip())
        tickets = []
        for j in xrange(n):
            u = raw_input().strip()
            v = raw_input().strip()
            tickets.append((u, v))
        print('Case #%d:%s' % (i + 1, SortAScrambledItinerary(tickets)))

if __name__ == '__main__':
    main()
