import httpx


class CodeTantraService:
    BASE_URL = "https://iiitb.codetantra.com"

    def __init__(self):
        self.client = httpx.AsyncClient(
            cookies={
                "JSESSIONID":"0AB56EAFDC12FBB665BEBF4516792227"

            }
        )

    async def fetch_raw_timetable(self, min_date, max_date):
        payload = {
            "showSelf": True,
            "minDate": min_date,
            "maxDate": max_date,
        }

        response = await self.client.post(
            f"{self.BASE_URL}/secure/rest/dd/mf",
            json=payload,
        )

        response.raise_for_status()

        print("Status:", response.status_code)
        print("Content-Type:", response.headers.get("content-type"))
        print("Length:", len(response.content))
        print("First 100 bytes:", response.content[:100])
        print(response.request.headers)
        return response.content
