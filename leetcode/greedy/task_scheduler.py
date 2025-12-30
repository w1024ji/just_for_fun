def leastInterval(self, tasks: List[str], n: int) -> int:
        counts = Counter(tasks)
        frequencies = list(counts.values())

        max_freq = max(frequencies) # 가장 높은 빈도

        max_freq_tasks_count = frequencies.count(max_freq)  # 가장 높은 빈도수를 가진 태스크가 몇 개인

        # (가장 빈번한 태스크 사이의 구역 수) * (한 구역의 길이) + (마지막 남은 태스크들)  
        answer = (max_freq - 1) * (n + 1) + max_freq_tasks_count

        return max(answer, len(tasks)) # 빈 슬로소다 태스크가 더 많을 수도 있으니까
