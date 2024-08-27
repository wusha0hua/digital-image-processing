function varargout = table_demo(varargin)
% TABLE_DEMO M-file for table_demo.fig
%      TABLE_DEMO, by itself, creates a new TABLE_DEMO or raises the existing
%      singleton*.
%
%      H = TABLE_DEMO returns the handle to a new TABLE_DEMO or the handle to
%      the existing singleton*.
%
%      TABLE_DEMO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in TABLE_DEMO.M with the given input arguments.
%
%      TABLE_DEMO('Property','Value',...) creates a new TABLE_DEMO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before table_demo_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to table_demo_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help table_demo

% Last Modified by GUIDE v2.5 07-Nov-2015 17:26:14

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @table_demo_OpeningFcn, ...
                   'gui_OutputFcn',  @table_demo_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before table_demo is made visible.
function table_demo_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to table_demo (see VARARGIN)

movegui(gcf, 'center');

% Choose default command line output for table_demo
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes table_demo wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = table_demo_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in push_ComputeComatrix.
function push_ComputeComatrix_Callback(hObject, eventdata, handles)
% hObject    handle to push_ComputeComatrix (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
path = [matlabroot, '\toolbox\images\imdemos\'];
image_index{1} = dir(fullfile(path, '*.tif'));
image_index{2} = dir(fullfile(path, '*.jpg'));
image_index{3} = dir(fullfile(path, '*.png'));
count = 0;
for k = 1 : length(image_index)
    for j = 1 : length(image_index{k})
        count = count + 1;
        FileName{count} = image_index{k}(j).name;
        CurrentImage = imread([path, image_index{k}(j).name]);
        if ndims(CurrentImage) == 3
            CurrentImage = rgb2gray(CurrentImage);
        end
        Comatrix{count} = graycomatrix(CurrentImage, 'Offset', [2, 0]);
        Feature{count} = graycoprops(Comatrix{count});
    end
end
Array = [];
for k = 1 : count
    temp{k} = {FileName{k}, Feature{k}.Contrast, Feature{k}.Correlation, Feature{k}.Energy, Feature{k}.Homogeneity};
    Array = [Array; temp{k}];
end
set(handles.uitable_GrayComatrix, 'data', Array);


% --- Executes during object creation, after setting all properties.
function uitable_GrayComatrix_CreateFcn(hObject, eventdata, handles)
% hObject    handle to uitable_GrayComatrix (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
set(hObject, 'ColumnName', {'FileName'; 'Contrast'; 'Correlation'; 'Energy'; 'Homogeneity'}, 'FontSize', 11);
