def solution(id_list, report, k):
    answer = [0] * len(id_list)
    report_vote = dict()
    report_member = dict()
    member_idx = dict()
    i = 0
    for id in id_list:
        report_vote[id] = 0
        report_member[id] = set()
        member_idx[id] = i
        i+=1
    for vote in report:
        repoter, repotee = vote.split(' ')
        if repoter not in report_member[repotee]:
            report_vote[repotee]+=1
            report_member[repotee].add(repoter)
    for id in id_list:
        if report_vote[id] >= k:
            for member in report_member[id]:
                answer[member_idx[member]]+=1
    return answer