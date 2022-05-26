import pickle

fname = "xf-n0012-il-1000000.csv"

raw = open(fname, 'r')
raw_str = raw.read()
raw_str_list = raw_str.split('\n')
for i in range(11):
    del raw_str_list[0]
del raw_str_list[-1]

# str_list_update_tmp = []
# for i in range(len(raw_str_list)):
#     if i%2 == 0:
#         str_list_update_tmp.append(raw_str_list[i])

# str_list_update = []
# for i in range(len(str_list_update_tmp)):
#     if i%2 == 0:
#         str_list_update.append(str_list_update_tmp[i])

data_mat = []
for line in raw_str_list:
    local = []
    line_l = line.split(',')
    if line_l[-1] == '':
        del line_l[-1]
    for j in line_l:
        local.append(float(j))
    data_mat.append(local)

# print(data_mat[-1])

raw_data = open("./data.pkl", 'wb')
pickle.dump(data_mat, raw_data)