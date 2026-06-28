import sys
sys.dont_write_bytecode = True 

def can_meet_order(ro, bo, s, rp, bp, d_red, d_blue, d_spare):
    r_rem = ro - d_red
    b_rem = bo - d_blue
    s_rem = s - d_spare
    if r_rem < 0 or b_rem < 0 or s_rem < 0:
        return False 
    need_r = max(0, rp - r_rem)
    need_b = max(0, bp - b_rem)
    return need_r + need_b <= s_rem
def brute_force_min_destroy(ro, bo, s, rp, bp):
    if ro + s < rp or bo + s < bp:
        return 0
    max_destroy = ro + bo + s
    for total_destroy in range(max_destroy + 1):
        for d_red in range(min(ro, total_destroy) + 1):
            for d_blue in range(min(bo, total_destroy - d_red) + 1):
                d_spare = total_destroy - d_red - d_blue
                if d_spare > s:
                    continue
                if can_meet_order(ro, bo, s, rp, bp, d_red, d_blue, d_spare):
                    break 
            else:
                continue
            break
        else:
            return total_destroy
    return max_destroy

ls=input().split()

res=brute_force_min_destroy(int(ls[0]),int(ls[1]),int(ls[2]),int(ls[3]),int(ls[4]))

print(res)