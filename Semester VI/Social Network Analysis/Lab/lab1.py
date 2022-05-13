import matplotlib.pyplot as plt 
import networkx as nx 

import urllib.request
import io 
import zipfile

# FOOTBALL CLUB 
url = "http://www-personal.umich.edu/~mejn/netdata/football.zip"
sock = urllib.request.urlopen (url)
sockRead = io.BytesIO (sock.read ())
sock.close ()

zf = zipfile.ZipFile (sockRead)
txt = zf.read ("football.txt").decode ()
gml = zf.read ("football.gml").decode ()
gml = gml.split ("\n") [1:]

FC = nx.parse_gml (gml)

# KARATE CLUB
KC = nx.karate_club_graph ()

# Graph Node Setting
options = {
    "node_color": "red",
    "node_size": 50,
    "linewidths": 0,
    "width": 0.1,
}

# DEGREE CENTRALITY
CD_KC = nx.degree_centrality (KC) # Degree Centrality for Karate Club
print ("\nDEGREE CENTRALITY: KARATE CLUB\n")
print (['%s %0.2f'%(node, CD_KC [node]) for node in CD_KC])

CD_FC = nx.degree_centrality (FC) # Degree Centrality for Football Club
print ("\nDEGREE CENTRALITY: FOOTBALL CLUB\n")
print (['%s %0.2f'%(node, CD_FC [node]) for node in CD_FC])


# BETWEENNESS CENTRALITY
CB_KC = nx.betweenness_centrality (KC, normalized = True, endpoints = False) # Betweenness Centrality for Karate Club
print ("\nBETWEENNESS CENTRALITY: KARATE CLUB\n")
print (['%s %0.2f'%(node, CB_KC [node]) for node in CB_KC])

CB_FC = nx.betweenness_centrality (FC, normalized = True, endpoints = False) # Betweenness Centrality for Football Club
print ("\nBETWEENNESS CENTRALITY: FOOTBALL CLUB\n")
print (['%s %0.2f'%(node, CB_FC [node]) for node in CB_FC])

# EIGENVECTOR CENTRALITY
CE_KC = nx.eigenvector_centrality (KC) # Eigenvector Centrality for Karate Club
print ("\nEIGENVECTOR CENTRALITY: KARATE CLUB\n")
print (['%s %0.2f'%(node, CE_KC [node]) for node in CE_KC])

CE_FC = nx.eigenvector_centrality(FC) # Eigenvector Centrality for Football Club
print ("\nEIGENVECTOR CENTRALITY: FOOTBALL CLUB\n")
print (['%s %0.2f'%(node, CE_FC [node]) for node in CE_FC])

# NETWORK GRAPHS
plt.figure (figsize = (15, 15))
plt.title ("KARATE CLUB NETWORK")
nx.draw_networkx (KC, with_labels = True, **options)

plt.figure (figsize = (15, 15))
plt.title ("FOOTBALL CLUB NETWORK")
nx.draw_networkx (FC, with_labels = True, **options)

plt.show ()