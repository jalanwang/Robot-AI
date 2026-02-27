#각 영역 별로 0이 아닌 영역 수 검출
red_count = cv2.countNonZero(mask_red)
green_count = cv2.countNonZero(mask_green)
yellow_count = cv2.countNonZero(mask_yellow)

# 가장 면적이 큰 색상 판별
areas = {'Red': red_count, 'Yellow': yellow_count, 'Green': green_count}
current_color = max(areas, key=areas.get)

print("현재 신호등 색상은:", current_color)
mask_dic = {'Red': mask_red, 'Yellow': mask_yellow, 'Green': mask_green}

current_mask = mask_dic[current_color]
mask_result = cv2.bitwise_and(image, image, mask=current_mask)
