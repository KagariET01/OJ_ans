while True:  #EOF輸出
    try:
        print(eval(input().replace('/','//')))  #eval為解方成函數，而整數除法則是//
    except:
        break