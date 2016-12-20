function preorder(node)
    if node then
        coroutine.yield(node.key)
        preorder(node.left)
        preorder(node.right)
    end
end

function preorder_iterator(tree)
    return coroutine.wrap(function() preorder(tree) end)
end

tree = {
    key = 'A',
    left = {
        key = 'B',
        left = { key = 'D' },
        right = { key = 'E' },
    },
    right = { key = 'C' },
}

for v in preorder_iterator(tree) do
    print(v)
end

----
print("====")

function tree_iterator(root)
    local function visit_inorder(node)
        if node.left ~= nil then
            visit_inorder(node.left)
        end

        coroutine.yield(node.key)

        if node.right ~= nil then
            visit_inorder(node.right)
        end
    end

    return coroutine.wrap(
        function() visit_inorder(root) end
    )
end

for e in tree_iterator(tree)
do
   print(e)
end
