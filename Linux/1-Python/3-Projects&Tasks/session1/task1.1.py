import facebook
groups=['107467485677870']
msg="hello"
token=input("token:")
graph=facebook.GraphAPI(access_token=token)

for group in groups:
    x=graph.put_object(group,'feed',message=msg)
    print(x)
    print("success")