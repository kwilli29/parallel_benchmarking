import pandas as pd

df = pd.read_csv("./cilk_test_000.csv")


df.to_excel("spawn_tests_cilk.xlsx", sheet_name="Sheet1", index=False)


