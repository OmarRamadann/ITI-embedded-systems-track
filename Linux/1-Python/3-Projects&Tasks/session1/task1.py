import requests
import facebook
#Your Access Keys
page_id_1 = 107467485677870
facebook_access_token_1 = 'EAAPS0p3Y5sgBAPo5Nt0Vm9vlGq8ZAaavH8KjJKZCRZCS0K3eyJwxJpYbBURllp40KAMczAgzat0THZCPQKZAA3ZC7iXGeWVZB0nyTvFSXZBxWFYoAFxGZAkEcwUP4lfZAZAKVhQ1sNOEKfZA6J2bgNyZAzrXECYZBaNh2pqcNk8v0anyIHPwwlEQY6EIU8w4LvjTziKy9cDv8Qy1HDbZBNxXazrDZC2n'
msg = 'ddd'
post_url = 'https://graph.facebook.com/{}/feed'.format(page_id_1)
#post_url = 'https://www.facebook.com/100092203603198/professional_dashboard/?ref=profile_action'.format(107467485677870)
payload = {
'message': msg,
'access_token': facebook_access_token_1
}
r = requests.post(post_url, data=payload)
print(r.text)