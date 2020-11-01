term = dict()

term["hole in one"] = 1
term["condor"] = -4
term["albatross"] = -3
term["eagle"] = -2
term["birdie"] = -1
term["par"] = 0
term["bogey"] = 1
term["double bogey"] = 2
term["triple bogey"] = 3

par = list(map(int, input().split()))
ans = 0
for i in range(18):
  str_ = input()
  if str_ != "hole in one":
    ans += term[str_] + par[i]
  else:
    ans += 1

print(ans)
