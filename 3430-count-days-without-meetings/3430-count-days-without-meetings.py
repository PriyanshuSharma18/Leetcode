from collections import defaultdict

class Solution:
    def countDays(self, days: int, meetings: list[list[int]]) -> int:
        day_map = defaultdict(int)
        prefix_sum = 0
        free_days = 0
        previous_day = days

        # Mark the start and end+1 of meetings
        for start, end in meetings:
            previous_day = min(previous_day, start)
            day_map[start] += 1
            day_map[end + 1] -= 1

        # Days before the first meeting
        free_days += previous_day - 1

        for current_day in sorted(day_map.keys()):
            if prefix_sum == 0:
                free_days += current_day - previous_day
            prefix_sum += day_map[current_day]
            previous_day = current_day

        # Days after the last meeting
        free_days += days - previous_day + 1

        return free_days