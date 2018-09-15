MATCH p = (:ColumnNode {columnId: 65878023})<-[:COLUMN_LINEAGE*0 .. 2]-(n:ColumnNode)
WHERE All(r in relationships(p) where r.lineageType = 1 or r.lineageType = 3)
WITH p, n OPTIONAL MATCH (n)-[r:COLUMN_LINEAGE]->(child:ColumnNode) WHERE r.lineageType = 1 or r.lineageType = 3
return n.columnId as columnId, n.tableId as tableId, -length(p) as hierarchy, collect(child.columnId) as childIds
UNION
MATCH p = (:ColumnNode {columnId: 65878023})-[:COLUMN_LINEAGE*0 .. 2]->(n:ColumnNode)
WHERE All(r in relationships(p) where r.lineageType = 1 or r.lineageType = 3)
WITH p, n OPTIONAL MATCH (n)-[r:COLUMN_LINEAGE]->(child:ColumnNode) WHERE r.lineageType = 1 or r.lineageType = 3
return n.columnId as columnId, n.tableId as tableId, length(p) as hierarchy, collect(child.columnId) as childIds


MATCH op=(:ColumnNode{columnId: 50})<-[:COLUMN_LINEAGE*]-(n:ColumnNode)
WHERE all ( r in relationships(op) where r.lineageType = 1 or r.lineageType = 3)
with n, relationships(op) as path return last(path).lineageId as lineageId, 
-length(path) as hierarchy, n.columnId as columnId, n.tableId as tableId
UNION
MATCH op=(:ColumnNode{columnId: 50})-[:COLUMN_LINEAGE*]->(n:ColumnNode)
WHERE all ( r in relationships(op) where r.lineageType = 1 or r.lineageType = 3)
with n, relationships(op) as path return last(path).lineageId as lineageId,
length(path) as hierarchy, n.columnId as columnId, n.tableId as tableId


MATCH (n:ColumnNode{columnId:%d}),(m:ColumnNode{columnId:%d}) 
with n,m
create (n)-[:COLUMN_LINEAGE{id:%s,lineageId:%d,lineageType:%d}]->(m);

create (:ColumnNode{columnId:%d,columnName:%s}) -[:COLUMN_LINEAGE{id:%s,lineageId:%d,lineageType:%d}]-> (:ColumnNode{columnId:%d,columnName:%s})

MATCH op=(:ColumnNode{columnId: {})<-[:COLUMN_LINEAGE*]-(n:ColumnNode)
with n, relationships(op) as path return last(path).lineageId as lineageId, 
-length(path) as hierarchy, n.columnId as columnId, n.tableId as tableId
UNION
MATCH op=(:ColumnNode{columnId: 50})-[:COLUMN_LINEAGE*0]->(n:ColumnNode)
with n, relationships(op) as path return last(path).lineageId as lineageId,
length(path) as hierarchy, n.columnId as columnId, n.tableId as tableId

match (n:ColumnNode{columnId:86817940}),(m:ColumnNode{columnId:65878021}) 
with n,m 
create (n)-[:COLUMN_LINEAGE{lineageId:261743,lineageType:1}]->(m) 

-- ahfakjkfa
MATCH p = (:ColumnNode {columnId: {rootId}})<-[:COLUMN_LINEAGE*0 .. %s]-(n:ColumnNode)
WHERE ALL(r in relationships(p) WHERE r.lineageType= %d or r.lineageType=%d)
WITH p, n OPTIONAL MATCH (n)-[r:COLUMN_LINEAGE]->(child:ColumnNode)
return n.columnId as columnId, n.tableId as tableId, -length(p) as hierarchy, collect(child.columnId) as childIds
UNION
MATCH p = (:ColumnNode {columnId: {rootId}})-[:COLUMN_LINEAGE*0 .. %s]->(n:ColumnNode)
WHERE ALL(r in relationships(p) WHERE r.lineageType= %d or r.lineageType=%d)
WITH p, n OPTIONAL MATCH (n)-[r:COLUMN_LINEAGE]->(child:ColumnNode)
return n.columnId as columnId, n.tableId as tableId, length(p) as hierarchy, collect(child.columnId) as childIds

--- FIXTIME
MATCH p = (n:ColumnNode {columnId: {headColumnId}})-[:COLUMN_LINEAGE*1 .. 10]->(m:ColumnNode {columnId: {tailColumnId}}) 
WHERE ALL(r in relationships(p) WHERE r.lineageType= %d or r.lineageType=%d or r.lineageType=%d)
UNWIND relationships(p)  AS  r
WITH DISTINCT r RETURN startNode(r).columnId AS parentId, endNode(r).columnId AS childId


MATCH op=(m:ColumnNode)-[:COLUMN_LINEAGE*0..2]->(n:ColumnNode) where m.columnId in [1,2,3]
AND ALL(r in relationships(op) WHERE r.lineageType= %d or r.lineageType=%d or r.lineageType=%d)
with n, relationships(op) as path return last(path).lineageId as lineageId, length(path) as hierarchy, n.tableId as tableId, n.columnId as columnId
    

MATCH op=(m:ColumnNode)<-[:COLUMN_LINEAGE*0..%s]-(n:ColumnNode) where m.columnId in $nodeIds
AND ALL(r in relationships(op) WHERE r.lineageType= %d or r.lineageType=%d or r.lineageType=%d)
with n, relationships(op) as path return last(path).lineageId as lineageId, -length(path) as hierarchy, n.tableId as tableId, n.columnId as columnId