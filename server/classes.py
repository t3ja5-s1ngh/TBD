import httpx
from datetime import datetime, timedelta

payload = {
    "filters": {
        "showSelf": True,
        "minDate": int(start.timestamp() * 1000),
        "maxDate": int(end.timestamp() * 1000)
    }
}

response = await client.post(
    "https://iiitb.codetantra.com/secure/rest/dd/mf",
    json=payload,
    cookies=cookies
)
