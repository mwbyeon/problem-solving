
for tc in xrange(input()):
    n, shy = raw_input().split()
    clap, invite = 0, 0
    for i, s in enumerate(shy):
        s = int(s)
        if i <= clap:
            clap += s
        else:
            invite += i - clap;
            clap += s + i - clap;
    print 'Case #%d: %d' % (tc+1, invite)

