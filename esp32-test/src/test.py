import asyncio
from services.ct import CodeTantraService


async def main():
    service = CodeTantraService()

    data = await service.fetch_raw_timetable(
        1783708200000,
        1783794600000
    )

    print(data)


asyncio.run(main())
