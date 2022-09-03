import json as js

def plan(sps, stags):
    ##
    # `print` in python is supported, 
    # if you want to know the data structures of these two args, 
    # just print them
    ##
    problems = js.load(sps)
    tags = js.load(stags)

    ret = []
    tm = {}
    for tag in tags:
        tm[tag["tag"]] = tag["refs"]

    for i in problems:
        if i["level"] == 1 and str(i["id"]) in tm["linked-list"]:
              # print("this problem has level: " + i["level"])
        # if i["level"] == 1:
            ret.append(str(i["id"])

    #return is list [strings]
    print(ret)
    return ret
