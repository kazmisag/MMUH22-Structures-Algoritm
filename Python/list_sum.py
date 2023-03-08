# define lists of different sizes and then calculate their sum

def sum_list(slist):
    sum =0
    for i in range(0, len(slist)):
        sum+=slist[i]

    return sum
    


def sum_list_rec(slist):
    if len(slist)== 0: return 0

    else:
        return slist[0]+sum_list_rec(slist[1:])


# Call the recursive function
sum =(sum_list_rec([2,3,4]))
print(sum)