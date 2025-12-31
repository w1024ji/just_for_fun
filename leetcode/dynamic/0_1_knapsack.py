cargo = [
  (4, 12),
  (2, 1),
  (10, 4),
  (1, 1),
  (2, 2)
]

def zero_one_knapsack(cargo):
  capacity = 15
  pack = []

  for i in range(len(cargo) + 1):
    pack.append([])
    for c in range(capacity + 1):
      if i == 0 or c == 0:
        pack[i].append(0)
      elif cargo[i - 1][1] <= c:
        pack[i].append(max(
          # 현재 아이템의 가치 + 남은 무게가 이전 아이템들로 채웠을 때의 최댓값
          cargo[i-1][0] + pack[i-1][c-cargo[i-1][1]], 
          # 이전 단계에서 구한 최댓값
          pack[i-1][c]
        ))
      else:
        pack[i].append(pack[i-1][c])

  return pack[-1][-1]

