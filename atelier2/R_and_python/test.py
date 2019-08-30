# -*- coding: utf-8 -*-
"""
Éditeur de Spyder
Ceci est un script temporaire.
"""

import pandas as pd
import numpy as np

def my_mean(table):
    return(np.mean(table))


#directory = "/home/claire/Documents/stat_of_the_R/FinistR2019/python_script/rp2016_td_pop1B1.csv"
#my_header = 34
#my_footer = 21
#pop1 = pd.read_csv(directory, header=6).iloc[:footer,]
#pop2 = pd.read_csv(directory, header=header).iloc[:-3,]

def get_df(directory,my_header,my_footer) :
    df = pd.read_csv(directory, header = my_header).iloc[:my_footer,]
    return(df)
    
#import json
#from pandas.io.json import json_normalize   
directory = "/home/claire/Documents/stat_of_the_R/FinistR2019/python_script/cities.json"

def read_json(directory) : 
    df = pd.read_json(path_or_buf = directory)
    return(df)

def return_input_type(my_object) : 
    return(type(my_object))
    
def return_input(my_object):
    return(my_object)

print(my_mean(1))