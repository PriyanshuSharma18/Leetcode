class Solution:
    def countDays(self, days: int, meetings: list[list[int]]) -> int:
        free_days = 0
        latest_end = 0

        # Sort meetings based on starting times
        meetings.sort()

        for start, end in meetings:
            # If there's a gap between previous end and current start
            if start > latest_end + 1:
                free_days += start - latest_end - 1

            # Extend the latest end to cover merged intervals
            latest_end = max(latest_end, end)

        # Add remaining days after last meeting ends
        free_days += days - latest_end

        return free_days