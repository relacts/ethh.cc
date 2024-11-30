local Rayfield = loadstring(game:HttpGet("https://sirius.menu/rayfield"))()

local Window =
    Rayfield:CreateWindow(
    {
        Name = "ethh.cc | MVS",
        Icon = locate,
        LoadingTitle = "v1.1.1",
        LoadingSubtitle = "by kaden",
        Theme = "Amethyst",
        DisableRayfieldPrompts = false,
        DisableBuildWarnings = false,
        ConfigurationSaving = {
            Enabled = true,
            FolderName = nil,
            FileName = "Big Hub"
        },
        Discord = {
            Enabled = false,
            Invite = "noinvitelink",
            RememberJoins = true
        },
        KeySystem = false,
        KeySettings = {
            Title = "Untitled",
            Subtitle = "Key System",
            Note = "No method of obtaining the key is provided",
            FileName = "Key",
            SaveKey = true,
            GrabKeyFromSite = false,
            Key = {"Hello"}
        }
    }
)

-- / Tab \\ --
local MainTab = Window:CreateTab("Main", house)

local VisualTab = Window:CreateTab("Visual", eye)

-- / Main Tab \\ --

local Input =
    MainTab:CreateInput(
    {
        Name = "Walkspeed ",
        CurrentValue = "16",
        PlaceholderText = "❗️16 - 100❗️",
        RemoveTextAfterFocusLost = true,
        Flag = "userws",
        Callback = function(Text)
            local player = game.Players.LocalPlayer
            local desiredWalkSpeed = (Text)

            local function applyWalkSpeed()
                player.Character:WaitForChild("Humanoid").WalkSpeed = desiredWalkSpeed
            end

            player.CharacterAdded:Connect(applyWalkSpeed)
            if player.Character then
                applyWalkSpeed()
            end
        end
    }
)

local Input =
    MainTab:CreateInput(
    {
        Name = "Jumpower",
        CurrentValue = "50",
        PlaceholderText = "❗️50 - 100❗️",
        RemoveTextAfterFocusLost = true,
        Flag = "Input1",
        Callback = function(Text)
            local desiredJumpPower = (Text) -- Set your desired JumpPower here

            local player = game.Players.LocalPlayer

            local function setJumpPower(character)
                local humanoid = character:WaitForChild("Humanoid")
                humanoid.JumpPower = desiredJumpPower
            end

            -- Apply JumpPower when the character spawns or respawns
            player.CharacterAdded:Connect(setJumpPower)

            -- Apply JumpPower immediately if the character already exists
            if player.Character then
                setJumpPower(player.Character)
            end
        end
    }
)

local Button =
    MainTab:CreateButton(
    {
        Name = "Launch button",
        Callback = function()
            local UserInputService = game:GetService("UserInputService")
            local Players = game:GetService("Players")
            local LocalPlayer = Players.LocalPlayer
            local TweenService = game:GetService("TweenService")

            -- Create the button
            local ScreenGui = Instance.new("ScreenGui")
            ScreenGui.Parent = LocalPlayer:WaitForChild("PlayerGui")

            local DashButton = Instance.new("TextButton")
            DashButton.Size = UDim2.new(0, 100, 0, 50)
            DashButton.Position = UDim2.new(1, -110, 0, 10) -- Positioned at the top right corner
            DashButton.BackgroundColor3 = Color3.new(0, 0, 0)
            DashButton.TextColor3 = Color3.new(1, 1, 1)
            DashButton.Text = "Dash"
            DashButton.Parent = ScreenGui

            local function dash()
                local humanoidRootPart =
                    LocalPlayer.Character and LocalPlayer.Character:FindFirstChild("HumanoidRootPart")
                if humanoidRootPart then
                    local dashDirection = humanoidRootPart.CFrame.LookVector * 15
                    local dashGoal = {}
                    dashGoal.CFrame = humanoidRootPart.CFrame + dashDirection
                    local tweenInfo = TweenInfo.new(0.2, Enum.EasingStyle.Linear)
                    local dashTween = TweenService:Create(humanoidRootPart, tweenInfo, dashGoal)
                    dashTween:Play()
                    dashTween.Completed:Wait()
                    humanoidRootPart.Velocity = Vector3.new()
                end
            end

            DashButton.MouseButton1Click:Connect(dash)
        end
    }
)

local Toggle =
    MainTab:CreateToggle(
    {
        Name = "Infinite jump",
        CurrentValue = false,
        Flag = "infj",
        Callback = function(Value)
            local UserInputService = game:GetService("UserInputService")
            local Players = game:GetService("Players")
            local LocalPlayer = Players.LocalPlayer

            _G.InfiniteJumpEnabled = not _G.InfiniteJumpEnabled

            UserInputService.JumpRequest:Connect(
                function()
                    if _G.InfiniteJumpEnabled then
                        LocalPlayer.Character:FindFirstChildOfClass("Humanoid"):ChangeState("Jumping")
                    end
                end
            )
        end
    }
)

local Toggle =
    MainTab:CreateToggle(
    {
        Name = "Noclip",
        CurrentValue = false,
        Flag = "noClip",
        Callback = function(Value)
            local Players = game:GetService("Players")
            local RunService = game:GetService("RunService")
            local LocalPlayer = Players.LocalPlayer

            _G.NoClipEnabled = not _G.NoClipEnabled

            RunService.Stepped:Connect(
                function()
                    if _G.NoClipEnabled and LocalPlayer.Character then
                        for _, part in pairs(LocalPlayer.Character:GetDescendants()) do
                            if part:IsA("BasePart") then
                                part.CanCollide = false
                            end
                        end
                    end
                end
            )
        end
    }
)

-- / Visual Tab \ --
